#include <bits/stdc++.h>
#include "grafo.h"
#define INF 214783647


using namespace std;

bool bfs(Grafo &grafo, vector<int> &distancias, vector<int> &mate) {
    queue<int> q;
    vector<pair<int, int>> arestas = grafo.getArestas(); 

    for (int i = 0; i < arestas.size(); i++) {
        int x = arestas[i].first;
        x++;
        if (mate[x] == 0) {
            distancias[x] = 0;
            q.push(x);
        } else 
            distancias[x] = INF;
    }

    distancias[0] = INF;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (distancias[x] < distancias[0]) {
            for (int y : grafo.vizinhos(x)) {
                if (distancias[mate[y]] == INF) {
                    distancias[mate[y]] = distancias[x] + 1;
                    q.push(mate[y]);
                }
            }
        }
    }
 
    return (distancias[0] != INF);
}
 
bool dfs(Grafo &grafo, vector<int> &distancias, vector<int> &mate, int x) {
    if (x != 0) {
        for (int y : grafo.vizinhos(x)) {
            if (distancias[mate[y]] == distancias[x]+1) {
                if (dfs(grafo, distancias, mate, mate[y]) == true) {
                    mate[y] = x;
                    mate[x] = y;
                    return true;
                }
            }
        }
        distancias[x] = INF;
        return false;
    }
    return true;
}
 
vector<int> hopcroft_karp(Grafo &grafo) {
    vector<pair<int, int>> arestas = grafo.getArestas();
    int vertices = grafo.qtdVertices();
    vector<int> distancias(vertices+1, INF);
    vector<int> mate(vertices+1, 0);

    while (bfs(grafo, distancias, mate)) {
        for (int i = 0; i < arestas.size(); i++) {
            int x = arestas[i].first;
            x++;
            if (mate[x] == 0)
                dfs(grafo, distancias, mate, x);
        }
    }
    return mate;
}
 
int main(int argv, char* argc[]) {
    Grafo grafo = Grafo(argc[1], 0);
    vector<int> mate = hopcroft_karp(grafo);
    vector<pair<int,int>> arestas;
    for (int i = 0; i < mate.size()/2 + 1; i++)
        if (mate[i])
            arestas.push_back(make_pair(i, mate[i]));
    sort(arestas.begin(), arestas.end());

    cout << arestas.size() << '\n';
    for (int i = 0; i < arestas.size(); i++) {
        cout << arestas[i].first << "-" << arestas[i].second;
        if (i != arestas.size()-1) cout << ",";
    }
    cout << '\n';
}
