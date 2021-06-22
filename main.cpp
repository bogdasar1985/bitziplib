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

    for(int i = 0; i < 255; i++)
    {
        tree_node fnd = s.find_node(i);
        if(fnd.count != 0)
        {
            char *str = s.get_code(fnd.sym).to_string();
            printf("%c : %s\n", fnd.sym, str);
            delete[] str;
        }
    }
    fclose(fl);
    return 0;
}
