#include "grafo.h"


using namespace std;

void dfs_2(Grafo &grafo, int v, bool* visitados, vector<vector<float>> transposta, vector<vector<int>> &componentes) {
    componentes.back().push_back(v);
    visitados[v] = true;
    for (int i = 0; i < grafo.qtdVertices(); i++)
        if ((int)transposta[v][i])
            if (!visitados[i])
                dfs_2(grafo, i, visitados, transposta, componentes);
}

void dfs_1(Grafo &grafo, int v, bool* visitados, stack<int> &pilha) {
    float** matriz = grafo.getMatrix();
    visitados[v] = true;
    for (int i = 0; i < grafo.qtdVertices(); i++)
        if ((int)matriz[v][i])
            if (!visitados[i])
                dfs_1(grafo, i, visitados, pilha);
    pilha.push(v);
}

vector<vector<int>> kosaraju(Grafo &grafo) {
    int vertices = grafo.qtdVertices();
    bool visitados[vertices];
    stack<int> pilha;
    for (int i = 0; i < vertices; i++)
        if (!visitados[i])
            dfs_1(grafo, i, visitados, pilha);

    for (int i = 0; i < vertices; i++) visitados[i] = false;
    float** matriz = grafo.getMatrix();
    vector<vector<float>> transposta(vertices, vector<float>(vertices));
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            transposta[j][i] = matriz[i][j];

    vector<vector<int>> componentes;
    while (!pilha.empty()) {
        int v = pilha.top();
        pilha.pop();
        if (!visitados[v]) {
            componentes.push_back(vector<int>());
            dfs_2(grafo, v, visitados, transposta, componentes);
        }
    }
    return componentes;
}

int main(int argv, char* argc[]) {
    Grafo grafo = Grafo(argc[1], 1);
    vector<vector<int>> componentes = kosaraju(grafo);
    sort(componentes.begin(), componentes.end());
    for (auto componente : componentes) {
        sort(componente.begin(), componente.end());
        for (int i = 0; i < componente.size(); i++) {
            cout << componente[i]+1;
            if (i != componente.size()-1) cout << ",";
        }
        cout << '\n';
    }
}
