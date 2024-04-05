#include "grafo.h"

using namespace std;


vector<int> bfs(string arquivo_grafo, int vertice);
vector<int> hierholtzer(string arquivo_grafo, int vertice);

void ex1() {
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

void ex2() {
    vector<int> distancias = bfs("facebook_santiago.net", 1);
    unordered_map<int, vector<int>> niveis;
    int max = 0;
    for (int i = 0; i < distancias.size(); i++) {
        if (distancias[i] > max) max = distancias[i];
        if (niveis.find(distancias[i]) == niveis.end())
            niveis.insert({distancias[i], vector<int>()});
        niveis[distancias[i]].push_back(i+1);
    }

    for (int i = 0; i < max; i++) {
        sort(niveis[i].begin(), niveis[i].end());
        cout << i << ": ";
        for (int j = 0; j < niveis[i].size()-1; j++)
            cout << niveis[i][j] << ',';
        cout << niveis[i][niveis[i].size()-1] << '\n';
    }
}

int main() {
    //ex1();
    //ex2();
    vector<int> ciclo = hierholtzer("facebook_santiago.net", 1);
}

vector<int> bfs(string arquivo_grafo, int vertice) {
    Grafo grafo = Grafo(arquivo_grafo);
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

vector<int> getSubciclo(Grafo &grafo, int vertice, vector<vector<bool>> &visitados) {
    vector<int> ciclo;
    int v = vertice - 1;
    ciclo.push_back(v);
    int inicio = v;
    while (true) {
        bool flag = true;
        for (int i = 0; i < grafo.qtdVertices(); i++)
            if (!visitados[v][i]) flag = false;
        if (flag) {
            ciclo.clear();
            break;
        }
        
        int u;
        for (int i = 0; i < grafo.qtdVertices(); i++)
            if (!visitados[v][i]) u = i;
        visitados[v][u] = true;
        v = u;
        ciclo.push_back(v);
        if (v == inicio) break;
    }

    for (int a : ciclo) {
        bool flag = true;
        for (int i = 0; i < grafo.qtdVertices(); i++)
            if (!visitados[a][i]) flag = false;
        if (flag) continue;

        vector<int> ciclo_linha = getSubciclo(grafo, a+1, visitados);
        if (ciclo_linha.empty()) {
            ciclo.clear();
            break;
        }
        for (int c : ciclo_linha)
            for (int d : ciclo) 
                if (c == d)
                    ciclo.insert(find(ciclo.begin(), ciclo.end(), c), ciclo_linha.begin(), ciclo_linha.end());
    }
    return ciclo; 
}

vector<int> hierholtzer(string arquivo_grafo, int vertice) {
    Grafo grafo = Grafo(arquivo_grafo);
    int vertices = grafo.qtdVertices();
    float** matriz = grafo.getMatrix();
    vector<vector<bool>> visitados(vertices, vector<bool>(vertices, true));
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            if (matriz[i][j]) visitados[i][j] = false;

    vector<int> ciclo = getSubciclo(grafo, vertice, visitados);
    if (ciclo.empty()) return ciclo;

    bool flag = false;
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            if (!visitados[i][j]) flag = true;
    if (flag) ciclo.clear();

    return ciclo;
}
