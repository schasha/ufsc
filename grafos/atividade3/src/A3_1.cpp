#include <bits/stdc++.h>
#include "grafo.h"


using namespace std;

int bfs(Grafo &grafo, int s, int t, vector<int> &anterior, vector<vector<int>> &capacidades, vector<vector<int>> &adj) {
    fill(anterior.begin(), anterior.end(), -1);
    anterior[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, 10000000});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int i = 0; i < grafo.qtdVertices(); i++) {
            int next = adj[cur][i] ? i : s;
            cout << next;
            if (anterior[next] == -1 && capacidades[cur][next]) {
                cout << 'b';
                anterior[next] = cur;
                int new_flow = min(flow, capacidades[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int edmons_karp(Grafo &grafo, int s, int t) {
    int fluxo = 0;
    int vertices = grafo.qtdVertices();
    vector<int> anterior(vertices);
    vector<vector<int>> capacidades(vertices, vector<int>(vertices, 0));
    vector<vector<int>> adj(vertices, vector<int>(vertices, 0));

    float** matriz = grafo.getMatrix();
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            capacidades[i][j] = matriz[i][j];

    // adjacentes nao dirigido
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            if ((int)matriz[i][j]) {
                adj[i][j] = 1;
                adj[j][i] = 1;
            }

    while (true) {
        int novo_fluxo = bfs(grafo, s, t, anterior, capacidades, adj);
        if (!novo_fluxo) break;
        cout << 'a';

        fluxo += novo_fluxo;
        int cur = t;

        while (cur != s) {
            int prev = anterior[cur];
            capacidades[prev][cur] -= novo_fluxo;
            capacidades[cur][prev] += novo_fluxo;
            cur = prev;
        }
    }

    return fluxo;
}


int main(int argv, char* argc[]) {
    Grafo grafo = Grafo(argc[1], 1);
    int fluxo = edmons_karp(grafo, 0, grafo.qtdVertices()-1);
    cout << fluxo << '\n';
}
