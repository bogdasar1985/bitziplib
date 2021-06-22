#include "huffman.hpp"
#include <stdio.h>
#include <string.h>
#include <limits.h>
int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        fprintf(stderr, "Need an argument\n");
        return 1;
    }
    FILE* fl = fopen(argv[1], "r");
    if(!fl)
    {
        fprintf(stderr, "Can't open file\n");
        return 2;
    }

    huffman s;
    char symbol = 0x0;
    while (fread(&symbol, 1, 1, fl) != 0)
    {
        s.add_symbol(symbol);
    }
    s.build_tree();
    fclose(fl);
    return 0;
}
