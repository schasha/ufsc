#ifndef GRAFO_H
#define GRAFO_H

#include <bits/stdc++.h>


using namespace std;

class Grafo {
 private:
    size_t n_vertices;
    size_t n_arestas;
    float** matriz;
    unordered_map<int, string> rotulos;

 public:
    //ler arquivo
    Grafo(string filename, int tipo) { //0 = nao-dirigido ; 1 = dirigido
        string s;
        ifstream file;
        file.open(filename);

        file >> s;
        file >> n_vertices >> ws;
        string v, vr;
        for (size_t i = 0; i < n_vertices; i++) {
            getline(file, s);
            stringstream ss(s);
            getline(ss, v, ' '); 
            getline(ss, vr);
            rotulos.insert({stoi(v)-1, vr});
        }

        file >> ws;
        file >> s;

        matriz = new float*[n_vertices];
        for (size_t i = 0; i < n_vertices; i++)
            matriz[i] = new float[n_vertices]();

        n_arestas = 0;
        int a, b; float p;
        while (file >> a >> b >> p) {
            a--; b--;
            matriz[a][b] = p;
            if (!tipo)
                matriz[b][a] = p;
            n_arestas++; 
        }
        file.close();
    }

    ~Grafo() {
        for (size_t i = 0; i < n_vertices; i++)
            delete matriz[i];
        delete matriz;
    }

    float** getMatrix() {
        return matriz;
    }

    size_t qtdVertices() {
        return n_vertices;
    }

    size_t qtdArestas() {
        return n_arestas;
    }

    size_t grau(int vertice) {
        vertice--;
        if (vertice >= n_vertices) throw out_of_range("out of range");

        int count = 0;
        for (size_t i = 0; i < n_vertices; i++)
            if (matriz[vertice][i])
                count++;
        return count;
    }

    string rotulo(int vertice) {
        vertice--;
        if (vertice >= n_vertices) throw out_of_range("out of range");
        return rotulos[vertice];
    }

    vector<int> vizinhos(int vertice) {
        vertice--;
        if (vertice >= n_vertices) throw out_of_range("out of range");

        vector<int> vizinhos;
        for (size_t i = 0; i < n_vertices; i++)
            if (matriz[vertice][i])
                vizinhos.push_back(i+1);
        return vizinhos;
    }

    bool haAresta(int v1, int v2) {
        v1--; v2--;
        if (v1 >= n_vertices || v2 >= n_vertices) throw out_of_range("out of range");
        return (bool) matriz[v1][v2];
    }

    float peso(int v1, int v2) {
        v1--; v2--;
        if (v1 >= n_vertices || v2 >= n_vertices) throw out_of_range("out of range");
        return matriz[v1][v2] != 0 ? matriz[v1][v2] : numeric_limits<float>::max();
    }
};

#endif
