#include "grafo.h"


using namespace std;

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

vector<int> hierholtzer(Grafo &grafo) {;
    int vertices = grafo.qtdVertices();
    float** matriz = grafo.getMatrix();
    vector<vector<bool>> visitados(vertices, vector<bool>(vertices, true));
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            if (matriz[i][j]) visitados[i][j] = false;

    vector<int> ciclo = getSubciclo(grafo, 1, visitados);
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

int main(int argv, char* argc[]) {
    Grafo grafo = Grafo(argc[1]);
    vector<int> ciclo = hierholtzer(grafo);
    if (!ciclo.empty()) { 
        cout << 1 << '\n';
        for (int i = 0; i < ciclo.size(); i++) {
            cout << ciclo[i];
            if (i != ciclo.size()-1) cout << ",";
        }
        cout << '\n';
    } else
        cout << 0 << '\n';
}
