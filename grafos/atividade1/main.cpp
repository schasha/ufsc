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

void ex3() {
    vector<int> ciclo = hierholtzer("ContemCicloEuleriano2.net", 1);
    if (!ciclo.empty()) cout << 1 << '\n';
    else                cout << 0 << '\n';
    for (int v : ciclo) cout << v << ' ';
    cout << '\n';
}

int main() {
    //ex1();
    //ex2();
    ex3();
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
        visitados[u][v] = true;
        v = u;
        ciclo.push_back(v);
        if (v == inicio) break;
    }

    for (int i = 0; i < ciclo.size(); i++) {
        bool flag = true;
        for (int j = 0; j < grafo.qtdVertices(); j++) {
            if (!visitados[ciclo[i]][j]) flag = false;
        }
        if (flag) continue;

        vector<int> ciclo_linha = getSubciclo(grafo, ciclo[i]+1, visitados);
        if (ciclo_linha.empty()) {
            ciclo.clear();
            break;
        }

        auto it = find(ciclo.begin(), ciclo.end(), ciclo_linha.at(0));
        if (it != ciclo.end())
            ciclo.insert(it, ciclo_linha.begin(), ciclo_linha.end()-1);
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

    for (int &v : ciclo)
        v++; 

    return ciclo;
}
