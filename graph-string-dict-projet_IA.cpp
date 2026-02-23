#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <limits>
#include <iomanip>

// Valeur représentant l'infini pour Floyd-Warshall
const double INF = std::numeric_limits<double>::infinity();

class Edge {
    double weight;
    class Vertex* destination;

    Edge(double w, Vertex* dest) : weight(w), destination(dest) {}
    friend class Vertex;
    friend class Graph;
};

class Vertex {
    std::string name;
    std::vector<Edge*> edges;

    Vertex(std::string n) : name(n) {}
    ~Vertex() {
        for (Edge* e : edges) delete e;
    }
    friend class Graph;
};

class Graph {
    std::vector<Vertex*> vertices;
    std::unordered_map<std::string, int> name_to_idx;
    std::vector<std::vector<double>> adj_matrix;

    // Ajoute un sommet s'il n'existe pas, retourne son indice
    int get_or_create_vertex(const std::string& name) {
        if (name_to_idx.find(name) == name_to_idx.end()) {
            name_to_idx[name] = vertices.size();
            vertices.push_back(new Vertex(name));
        }
        return name_to_idx[name];
    }

    // Fonction récursive pour le DFS
    void dfs_recursive(int v_idx, std::set<int>& visited) {
        visited.insert(v_idx);
        std::cout << vertices[v_idx]->name << " ";

        for (Edge* edge : vertices[v_idx]->edges) {
            int neighbor_idx = name_to_idx[edge->destination->name];
            if (visited.find(neighbor_idx) == visited.end()) {
                dfs_recursive(neighbor_idx, visited);
            }
        }
    }

public:
    ~Graph() {
        for (Vertex* v : vertices) delete v;
    }

    void add_edge(const std::string& from, const std::string& to, double value) {
        int u = get_or_create_vertex(from);
        int v = get_or_create_vertex(to);
        vertices[u]->edges.push_back(new Edge(value, vertices[v]));
    }

    void dfs() {
        std::set<int> visited;
        std::cout << "DFS traversal: ";
        for (size_t i = 0; i < vertices.size(); ++i) {
            if (visited.find(i) == visited.end()) {
                dfs_recursive(i, visited);
            }
        }
        std::cout << std::endl;
    }

    void build_adjacency_matrix() {
        int n = vertices.size();
        adj_matrix.assign(n, std::vector<double>(n, INF));

        for (int i = 0; i < n; ++i) {
            adj_matrix[i][i] = 0; // Distance vers soi-même
            for (Edge* edge : vertices[i]->edges) {
                int j = name_to_idx[edge->destination->name];
                adj_matrix[i][j] = edge->weight;
            }
        }
    }

    void floyd_warshall() {
        build_adjacency_matrix();
        int n = vertices.size();
        
        // Algorithme de Floyd-Warshall
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (adj_matrix[i][k] != INF && adj_matrix[k][j] != INF) {
                        if (adj_matrix[i][j] > adj_matrix[i][k] + adj_matrix[k][j]) {
                            adj_matrix[i][j] = adj_matrix[i][k] + adj_matrix[k][j];
                        }
                    }
                }
            }
        }

        // Affichage du résultat
        std::cout << "\nMatrice des plus courts chemins (Floyd-Warshall) :" << std::endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (adj_matrix[i][j] == INF) std::cout << std::setw(6) << "INF";
                else std::cout << std::setw(6) << adj_matrix[i][j];
            }
            std::cout << std::endl;
        }
    }
};

// Votre fonction read_triplet modifiée pour utiliser Graph correctement
Graph read_triplet(const std::string &filename) {
    Graph g;
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("File " + filename + " not found");
    }

    std::string from, to;
    double value;
    while (file >> from >> to >> value) {
        g.add_edge(from, to, value);
    }
    file.close();
    return g;
}

int main() {
    try {
        // Création d'un fichier de test localement pour l'exemple
        std::ofstream outfile("graph0.gr");
        outfile << "Paris Lyon 100\nParis Nice 200\nLyon Nice 50\nNice Marseille 30";
        outfile.close();

        Graph graph = read_triplet("graph0.gr");
        
        graph.dfs();
        graph.floyd_warshall();

    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}