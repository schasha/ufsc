#include "grafo.h"


using namespace std;

void dfs_2(Grafo &grafo, int v, bool* visitados, float** transposta) {
    component[x] = numComponents;
    components[numComponents].push_back(x);
    visitados[v] = true;
    for (int i = 0; i < grafo.qtdVertices(); i++)
        if (!visitados[(int)transposta[v][i]])
            dfs_2(grafo, transposta[v][i], visitados, transposta);
}

void dfs_1(Grafo &grafo, int v, bool* visitados, stack<int> &pilha) {
    float** matriz = grafo.getMatrix();
    visitados[v] = true;
    for (int i = 0; i < grafo.qtdVertices(); i++)
        if (!visitados[(int)matriz[v][i]])
            dfs_1(grafo, matriz[v][i], visitados, pilha);
    pilha.push(v);
}

vector<vector<int>> kosaraju(Grafo &grafo) {
    int vertices = grafo.qtdVertices();
    bool visitados[vertices];
    stack<int> pilha;

    int component[vertices];
    vector<int> components[vertices];
    int numComponents;

    for (int i = 0; i < vertices; i++)
        if (!visitados[i])
            dfs_1(grafo, i, visitados, pilha);

    for (int i = 0; i < vertices; i++) visitados[i] = false;
    float** matriz = grafo.getMatrix();
    float** transposta;
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            transposta[j][i] = matriz[i][j];

    vector<vector<int>> componentes;
    while (!pilha.empty()) {
        int v = pilha.top();
        pilha.pop();
        if (!visitados[v]) {
            dfs_2(v);
            num_c++;
        }
    }
}

int main(int argv, char* argc[]) {
    Grafo grafo = Grafo(argc[1]);
    vector<vector<int>> componentes = kosaraju(grafo);
    for (auto componente : componentes) {
        for (int v : componente)
            cout << v << ",";
        cout << '\n';
    }
}
