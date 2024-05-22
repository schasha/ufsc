#include "grafo.h"


using namespace std;

void dfs(Grafo &grafo, int v, bool* visitados, vector<int> &ord) {
    float** matriz = grafo.getMatrix();
    visitados[v] = true;
    for (int i = 0; i < grafo.qtdVertices(); i++)
        if ((int)matriz[v][i])
            if (!visitados[i])
                dfs(grafo, i, visitados, ord);
    ord.insert(ord.begin(), v);
}

vector<int> ordenacao_topologica(Grafo &grafo) {
    int vertices = grafo.qtdVertices();
    bool visitados[vertices];
    memset(visitados, false, vertices);
    vector<int> ord; 
    for (int i = 0; i < vertices; i++)
        if (!visitados[i])
            dfs(grafo, i, visitados, ord);
    return ord;
}

int main(int argv, char* argc[]) {
    Grafo grafo = Grafo(argc[1], 1);
    vector<int> ord = ordenacao_topologica(grafo);
    for (int v : ord) {
        cout << grafo.rotulo(v+1);
        if (v != *(ord.end()-1)) cout << " -> ";
    }
    cout << '\n';
}
