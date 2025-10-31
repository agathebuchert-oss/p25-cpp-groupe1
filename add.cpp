#include <iostream>

int add(int a, int b)
{
    return a + b;
}

int con(char str[])
{
    int v = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        char a = str[i];
        v = v * 10 + a - '0';
    }
    return v;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "not enough arguments" << std::endl;
    }
    else
    {
        int s = 0;
        int i = 1;
        while (i < argc)
        {
            int a = con(argv[i]);
            s = add(s, a);
            i = i + 1;
        }

        std::cout << "le résultat est " << s << std::endl;
    }
    return 0;
}