#include "grafo.h"

int main() {
    Grafo grafo = Grafo("facebook_santiago.net");
    cout << grafo.qtdVertices() << '\n';
    cout << grafo.qtdArestas() << '\n';
    cout << grafo.grau(3) << '\n';
    cout << grafo.rotulo(3) << '\n';
    vector<int> vizinhos = grafo.vizinhos(3);
    for (int v : vizinhos)
        cout << v << ' ';
    cout << '\n';
    cout << grafo.haAresta(3, 632) << '\n';
    cout << grafo.peso(3, 632) << '\n';
}
