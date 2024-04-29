#include "grafo.h"


using namespace std;

vector<vector<int>> floydWarshall(Grafo &grafo) {
    int inf = numeric_limits<int>::max();
    int vertices = grafo.qtdVertices();
    float** matriz = grafo.getMatrix();
    vector<vector<int>> distancias(vertices, vector<int>(vertices));
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            if (matriz[i][j])
                distancias[i][j] = matriz[i][j];
            else
                distancias[i][j] = inf;

    for (int k = 0; k < vertices; k++)
        for (int i = 0; i < vertices; i++)
            for (int j = 0; j < vertices; j++)
                if (distancias[i][j] > (distancias[i][k] + distancias[k][j])
                    && (distancias[k][j] != inf && distancias[i][k] != inf))
                    distancias[i][j] = distancias[i][k] + distancias[k][j];
   return distancias; 
}

int main(int argv, char* argc[]) {
    Grafo grafo = Grafo(argc[1]);
    vector<vector<int>> distancias = floydWarshall(grafo);
    for (int i = 0; i < grafo.qtdVertices(); i++) {
        cout << i+1 << ":";
        for (int j = 0; j < grafo.qtdVertices(); j++) {
            cout << distancias[i][j];
            if (j != grafo.qtdVertices()-1) cout << ",";
        }
        cout << '\n';
    }
}

