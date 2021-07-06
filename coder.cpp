#include "huffman.hpp"
#include <stdio.h>
int main(int argc, char* argv[])
{
    char sym;
    scanf("%c", &sym);

    huffman::huffman s;
    huffman::add_symbol(s, 'a');
    huffman::add_symbol(s, 'b');
    huffman::build_tree(s);
    auto r = huffman::get_code(s, sym);
    if(r.get_size() == 0)
    {
        printf("Нода не найдена!\n");
    }
    else
    {
        printf("%c %s\n", sym, r.to_string());
    }
    return 0;
}
