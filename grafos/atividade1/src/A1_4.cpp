#include "grafo.h"


using namespace std;

pair<vector<int>, vector<int>> dijkstra(Grafo &grafo, int vertice) {
    vertice--;
    int vertices = grafo.qtdVertices();
    vector<int> distancias(vertices, numeric_limits<int>::max());
    vector<int> prev(vertices, -1);
    priority_queue<int, vector<int>, greater<int>> heap;
    distancias[vertice] = 0;
    heap.push(vertice);
    while (!heap.empty()) {
        int u = heap.top();
        heap.pop();
        for (int v : grafo.vizinhos(u+1)) {
            v--;
            int peso = grafo.getMatrix()[u][v];
            if (distancias[v] > distancias[u] + peso) {
                distancias[v] = distancias[u] + peso;
                heap.push(v);
                prev[v] = u;
            }
        }
    }
    return make_pair(distancias, prev);
}

int main(int argv, char* argc[]) {
    Grafo grafo = Grafo(argc[1]);
    auto p = dijkstra(grafo, atoi(argc[2]));
    auto distancias = p.first;
    auto prev = p.second;
    for (size_t i = 0; i < prev.size(); i++) {
        cout << i+1 << ": ";
        vector<int> caminho{(int)i+1};
        while (true) {
            if (prev[caminho[0]-1] == -1) break;
            caminho.insert(caminho.begin(), prev[caminho[0]-1]+1);
        }

        for (size_t j = 0; j < caminho.size(); j++) {
            cout << caminho[j];
            if (j != caminho.size()-1) cout << ",";
        }
        cout << "; ";
        cout << "d=" << distancias[i] << '\n';
    }
}
