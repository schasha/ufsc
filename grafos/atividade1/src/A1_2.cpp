#include "grafo.h"


using namespace std;

vector<int> bfs(Grafo &grafo, int vertice) {
    vector<int> distancias(grafo.qtdVertices(), -1);
    bool conhecidos[grafo.qtdVertices()];
    memset(conhecidos, false, grafo.qtdVertices());
    queue<int> fila;

    vertice--;
    distancias[vertice] = 0;
    conhecidos[vertice] = true;
    fila.push(vertice);
    while(!fila.empty()) {
        int u = fila.front();
        fila.pop();
        for (int v : grafo.vizinhos(u+1)) {
            v--;
            if (conhecidos[v] == false) {
                conhecidos[v] = true;
                distancias[v] = distancias[u] + 1;
                fila.push(v);
            }
        }
    }
    return distancias;
}

int main(int argv, char* argc[]) {
    Grafo grafo = Grafo(argc[1]);
    vector<int> distancias = bfs(grafo, atoi(argc[2]));
    unordered_map<int, vector<int>> niveis;
    int max = 0;
    for (int i = 0; i < distancias.size(); i++) {
        if (distancias[i] > max) max = distancias[i];
        if (niveis.find(distancias[i]) == niveis.end())
            niveis.insert({distancias[i], vector<int>()});
        niveis[distancias[i]].push_back(i+1);
    }

    for (int i = 0; i <= max; i++) {
        sort(niveis[i].begin(), niveis[i].end());
        cout << i << ": ";
        for (int j = 0; j < niveis[i].size()-1; j++)
            cout << niveis[i][j] << ',';
        cout << niveis[i][niveis[i].size()-1] << '\n';
    }
}
