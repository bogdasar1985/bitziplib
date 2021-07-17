#include "huffman.hpp"
#include <stdio.h>
#include <string.h>
#include <limits.h>
int main(int argc, char *argv[])
{
    FILE *source_fl = NULL;
    FILE *result_fl = NULL;
    char symbol;
    char bits = '\0';
    char* result = new char[128];
    memset(result, '\0', 128);
    char bit_counter = 0;
    size_t bit_position = 7;

    huffman::huffman s;

    if(argc < 3)
    {
        fprintf(stderr, "Too few arguments!\n");
        return 1;
    }

    // Get file for compressing
    source_fl = fopen(argv[1], "r+");
    if(source_fl == NULL)
    {
        return 2;
    }

    // Get file for write compress result
    result_fl = fopen(argv[2], "w+");
    if(result_fl == NULL)
    {
        return 3;
    }

    // Add all symbols from file to tree
    while(fread(&symbol, 1, 1, source_fl) != 0)
    {
        huffman::add_symbol(s, symbol);
    }

    // Make a temp PQ for writing, because we loose them after build tree (NOT BEST IDEA)
    hf_priority_queue tmp_pq = s.pq;
    huffman::build_tree(s);

    // On this pass, we do not write anything, we just get the number of extra bits.
    fseek(source_fl, 0, SEEK_SET);
    while(fread(&symbol, 1, 1, source_fl) != 0)
    {
        huffman::get_code(s, symbol, &result);
        size_t size = strlen(result);
        for(size_t i = 0; i < size; ++i)
        {
            if(result[i] == '0')
            {
                bits &= (char)~(1UL << bit_position);
            }
            if(result[i] == '1')
            {
                bits |= (char)(1UL << bit_position);
            }
            ++bit_counter;
            --bit_position;
            if(bit_counter == 8)
            {
                bit_position = 7;
                bit_counter = 0;
                bits = '\0';
            }
        }
        memset(result, '\0', 128);
    }

    if(bit_counter != 0)
    {
        bit_counter = 8 - bit_counter;
    }

    size_t pq_size = tmp_pq.size();
    fwrite(&bit_counter, sizeof(bit_counter), 1, result_fl);   // Writing info about less_bits
    fwrite(&(pq_size), sizeof(pq_size), 1, result_fl); // Writing info about queue size

    // Queue writing
    tmp_pq.serialize(result_fl);

    bit_counter = 0;
    bit_position = 7;
    bits = '\0';

    // Write in file
    fseek(source_fl, 0, SEEK_SET);
    while(fread(&symbol, 1, 1, source_fl) != 0)
    {
        huffman::get_code(s, symbol, &result);
        size_t size = strlen(result);
        for(size_t i = 0; i < size; ++i)
        {
            if(result[i] == '0')
            {
                bits &= (char)(~(1UL << bit_position));
            }
            if(result[i] == '1')
            {
                bits |= (char)(1UL << bit_position);
            }
            ++bit_counter;
            --bit_position;
            if(bit_counter == 8)
            {
                fwrite(&bits, sizeof(bits), 1, result_fl);
                bit_position = 7;
                bit_counter = 0;
                bits = '\0';
            }
        }
        memset(result, '\0', 128);
    }

    // Writing extra bits
    if(bit_counter > 0)
    {
        fwrite(&bits, 1, 1, result_fl);
    }

    fclose(source_fl);
    fclose(result_fl);
    delete[] result;
    return 0;
}