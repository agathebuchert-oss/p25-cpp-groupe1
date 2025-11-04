#include <iostream>

int str_to_int(char a[])
{
    int s = 0;

    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] < '0' || a[i] > '9')
        {
            return -1;
        }
    }
    int n = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        n = n * 10 + a[i] - '0';
    }
    return n;
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << "not enough arguments" << std::endl;
        return 0;
    }
    int n = str_to_int(argv[1]);
    if (n == 0)
    {
        std::cout << "le résultat est " << 1 << std::endl;
        return 0;
    }
    if (n == -1)
    {
        std::cout << "arguments are not correct" << std::endl;
        return 0;
    }
    int f = 1;
    for (int i = 1; i <= n; i++)
    {
        f = f * i;
    }
    std::cout << "le résulat est " << f << std::endl;

    return 0;
}