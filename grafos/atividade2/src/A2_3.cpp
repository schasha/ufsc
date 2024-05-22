#include "grafo.h"


using namespace std;
set<tuple<int, int, float>> kruskal(Grafo &grafo) {
    float** matriz = grafo.getMatrix();
    vector<tuple<int, int, float>> arestas;
    for (int i = 0; i < grafo.qtdVertices(); i++)
        for (int j = 0; j < grafo.qtdVertices(); j++)
            if (matriz[i][j] > 0)
                arestas.push_back({i, j, matriz[i][j]});

    sort(arestas.begin(), arestas.end(), [](tuple<int, int, float> a, tuple<int, int, float> b) -> bool {
                                            return get<2>(a) < get<2>(b);});


    vector<set<int>> arvores;
    for (int i = 0; i < grafo.qtdVertices(); i++) {
        set<int> set;
        set.insert(i);
        arvores.push_back(set);
    }

    set<tuple<int, int, float>> mst;
    for (auto a : arestas) {
        int u = get<0>(a);
        int v = get<1>(a);
        float p = get<2>(a);
        if (arvores[u] != arvores[v]) {
            mst.insert({u, v, p});
            arvores[u].insert(arvores[v].begin(), arvores[v].end());
            for (int i : arvores[u])
                arvores[i] = arvores[u];
        }
    }
    return mst;
}

int main(int argv, char* argc[]) {
    Grafo grafo = Grafo(argc[1], 0);
    set<tuple<int, int, float>> mst = kruskal(grafo);
    float soma = 0;
    stringstream out;
    for (auto l : mst) {
        int u = get<0>(l);
        int v = get<1>(l);
        float p = get<2>(l);

        soma += p;
        out << u+1 << "-" << v+1 << ", ";
    }
    string s = out.str();
    s.erase(s.end()-2);
    cout << soma << '\n';
    cout << s << '\n';
}
