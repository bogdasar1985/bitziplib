#include "huffman.hpp"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "priority_queue.hpp"
// Читаем файл
// Строим дерево
// Пишем в файл длину очереди
// Пишем очередь в новый файл
// Определяем кол-во лишних бит и пишем их в файл
// Пишем биты в файл

int main(int argc, char* argv[])
{
    priority_queue pq;
    if(argc < 3)
    {
        fprintf(stderr, "Need an arguments\n");
        return 1;
    }
    
    int read_fl = open(argv[1], O_RDONLY);
    if(!read_fl)
    {
        fprintf(stderr, "Can't open read file\n");
        return 2;
    }

    int write_fl = open(argv[2], O_RDWR | O_CREAT, 0666);
    if(!write_fl)
    {
        fprintf(stderr, "Can't open write file!\n");
        return 3;
    }

    huffman::huffman s;
    char symbol = 0x0;
    while (read(read_fl, &symbol, 1) != 0)
    {
        huffman::add_symbol(s, symbol);
    }

    // Write queue size in elements
    unsigned int pq_size = huffman::pq_size(s);
    int res = write(write_fl, &pq_size, sizeof(pq_size)); // specify cross-platform size
    if(res < 0)
    {
        fprintf(stderr, "Can't write to file");
        return 4;
    }
    
    huffman::build_tree(s);

    close(read_fl);
    return 0;
}
