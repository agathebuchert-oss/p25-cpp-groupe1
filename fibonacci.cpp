#include <iostream>

int str_to_int(char a[])
{
    int n = a[0] - '0';
    return n;
}

int main(int agrc, char *argv[])
{
    int n = str_to_int(argv[1]);
    int f = 0;
    for (int i = 0; i <= n; i++)
    {
        f = f + i;
    }
    std::cout << "le résulat est " << f << std::endl;

    return 0;
}