#include <iostream>

struct Edge;

struct Vertex
{
    int name;
    Vertex(int n) : name(n) {}
    std::vector<Edge *> edges;

    void add_edge(Edge *pe)
    {
        edges.push_back(pe);
    }

    void print();
};

struct Edge
{
    double value;
    Vertex *begin;
    Vertex *end;

    Edge(double v, Vertex *b, Vertex *e) : value(v), begin(b), end(e) {}

    void print()
    {
        std::cout << begin->name << "-" << "(" << value << ")" << "->" << end->name << std::endl;
    }
};

inline void Vertex::print()
{
    for (int i=0; i < edges.size(); i++)
    {
        edges[i]->print();
    }
}


struct Graph
{
    std::vector<Vertex *>v;

    void add_edge(int begin, int end, double poid)
    {
        add_vertex(begin);
        add_vertex(end);
        v[begin]->add_edge(new Edge(poid, v[begin], v[end]));
    }

    void add_vertex(int name)
    {
        if (v.size() < name)
        {
            for (int i = v.size(); i <= name; i++)
            {
                v.push_back(new Vertex(i));
            }
        }
    }

    void print()
    {
        // for (Vertex* e : v) 
        //     v->print();
        
        for (int i=0; i < v.size(); i++)
        {
            v[i]->print();
        }
    }
};

int main()
{
    Graph g;

    g.add_edge(2, 5, 17.9);
    g.add_edge(5, 3, 23.9);
    g.add_edge(3, 4, 16.9);
    g.add_edge(4, 0, 699.9);
    g.print();
}
