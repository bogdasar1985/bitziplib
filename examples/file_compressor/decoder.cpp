#include <sys/stat.h>
#include <limits.h>
#include "huffman.hpp"
#define CODE_SIZE 256
int main(int argc, char *argv[])
{
    FILE *source_fl = NULL;
    FILE *result_fl = NULL;
    char less_bits = 0;
    size_t pq_size = 0;
    char code[CODE_SIZE];
    struct stat stats;
    char ch;
    size_t pos = 0;

    huffman::huffman s;
    memset(code, '\0', CODE_SIZE);
    
    if(argc < 3)
    {
        fprintf(stderr, "Too few arguments!\n");
        return 1;
    }

    source_fl = fopen(argv[1], "r+");
    if(source_fl == NULL)
    {
        return -1;
    }

    result_fl = fopen(argv[2], "w+");
    if(result_fl == NULL)
    {
        return -2;
    }

    fread(&less_bits, sizeof(char), 1, source_fl);
    fread(&pq_size, sizeof(pq_size), 1, source_fl);

    // Fill a priority_queue
    s.pq.deserialize(source_fl, pq_size);
    
    // Build a tree
    huffman::build_tree(s);
    
    fstat(fileno(source_fl), &stats);
    for(long i = ftell(source_fl); i < stats.st_size; ++i)
    {
        char sym = 0;
        fread(&ch, 1, 1, source_fl);
        if(i == stats.st_size - 1)
        {
            for(int i = CHAR_BIT-1; i >= less_bits; --i)
            {
                code[pos] = ((ch & (1 << i)) >> i) + '0';
                ++pos;
                if((sym = huffman::get_symbol(s, code)) != -1)
                {
                    fwrite(&sym, 1, 1, result_fl);
                    memset(code, '\0', CODE_SIZE);
                    pos = 0;
                }
            }
        }
        else
        {
            for(int i = CHAR_BIT-1; i >= 0; --i)
            {
                code[pos] = ((ch & (1 << i)) >> i) + '0';
                ++pos;
                if((sym = huffman::get_symbol(s, code)) != -1)
                {
                    fwrite(&sym, 1, 1, result_fl);
                    memset(code, '\0', CODE_SIZE);
                    pos = 0;
                }
            }
        }
    }

    fclose(source_fl);
    fclose(result_fl);
    return 0;
}