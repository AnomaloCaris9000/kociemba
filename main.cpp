#include <stdlib.h>
#include <iostream>


#define print(x) std::cout << x << std::endl;


int main(int argc, char **argv)
{
    print("Hello World!");
    for(int i = 1; i < argc; i++)
    {
        print(argv[i]);
    }
    exit(EXIT_SUCCESS); 
}