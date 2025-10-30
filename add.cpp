#include <iostream>
#include <cstdlib>

int add(int a, int b)
{
    return a + b;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "not enough arguments" << std::endl;
    }
    int s = 0;
    int i = 1;
    while (i < argc)
    {
        int a = std::atoi(argv[i]);
        s = add(s, a);
        i = i + 1;
    }
    std::cout << "le résultat est " << s << std::endl;

    return 0;
}