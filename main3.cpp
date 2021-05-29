#include "dynamic_array.hpp"
#include <stdio.h>
#include <vector>
int main()
{
    dynamic_array<int> d;
    
    d.push_back(1);
    d.push_back(2);
    //d.push_back(3);
    d.push_back(4);
    d.push_back(5);
    d.erase(0);
    for (size_t i = 0; i < d.size(); i++)
    {
        printf("%d\n", d[i]);
    }
    return 0;
}