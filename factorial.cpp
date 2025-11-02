#include <iostream>

int str_to_int(char a[])
{
    int n = a[0] - '0';
    return n;
}

int main(int agrc, char *argv[])
{
    int n = str_to_int(argv[1]);
    if (n == 0)
    {
        std::cout << "le résultat est " << 1 << std::endl;
    }
    int f = 1;
    for (int i = 1; i <= n; i++)
    {
        f = f * i;
    }
    std::cout << "le résulat est " << f << std::endl;

    return 0;
}