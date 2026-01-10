#include <iostream>
int *create(int size)
{
    int *t = new int[5];
    return t;
}

void deletestack(int *stack)
{
    delete[] stack;
}

class stack
{
    int nb;
    int size;
    int *tab;

    stack(int s) : size(s), nb(0)
    {
        tab = new int[size]; // allocation 
    }

    stack(const stack& other) : nb(other.nb), size(other.size)
    {
        tab = new int[size];
        for (int i = 0, i < nb, i++)
        {
            tab[i] = other.tab[i];
        }
    }

    void operator=(const stack& other)
    {
        if (this != &other)
        {
            delete [] tab;
            nb = other.nb;
            size = other.size;
            tab = new int[size];
            for (int i = 0; i < nb; i++)
            {
                tab[i] = other.tab[i];
            }
        }
    }

    ~stack(){ // destruteur
        delete [] tab;
    }

    bool is_full()
    {
        return nb >= size;
    }

    void push(int v)
    {
        tab[nb] = v;
        nb = nb + 1;
    }
};

int main()
{
    stack st(15);
    st.push(-17);

    stack* ps = new stack(20000);
    ps->push(-17);
    delete ps;

    return 0;
}