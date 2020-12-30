#include "random.hpp"
#include <cstdio>
#include <iostream>

// this is just a test program to see if int get_random_function(int,int) is actually random

int main(int argc, char *argv[]) {
    int arr[2] {0,0};

    for (int i = 0; i < 1000; ++i)
        ++arr[ get_random_num(0,1) ];

    printf("0: [%d]\n1: [%d]\n", arr[0], arr[1]);

    if (argc < 2)
        std::cin.get();

    return 0;
}
