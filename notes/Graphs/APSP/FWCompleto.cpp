#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int AdjMat[405][405];
int parent[405][405];  // para reconstruir o caminho

void printPath(int i, int j) {
    if (i == j) {
        cout << i;
        return;
    }
    if (parent[i][j] == -1) {
        cout << "Sem caminho";
        return;
    }
    
    printPath(i, parent[i][j]);
    cout << " -> " << j;
}

void floyd_warshall(int V) {
    // Inicializa parents
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            parent[i][j] = (i != j && AdjMat[i][j] != INF) ? i : -1;
    
    // Floyd-Warshall com reconstrução de caminho
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (AdjMat[i][k] + AdjMat[k][j] < AdjMat[i][j]) {
                    AdjMat[i][j] = AdjMat[i][k] + AdjMat[k][j];
                    parent[i][j] = parent[k][j];  // salva o predecessor
                }
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            AdjMat[i][j] = (i == j) ? 0 : INF;
    
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        AdjMat[u][v] = w;
    }
    
    floyd_warshall(V);
    
    // Exemplo: imprime todos os caminhos do vértice 0
    cout << "Caminhos a partir do vértice 0:\n";
    for (int j = 0; j < V; j++) {
        cout << "0 -> " << j << " (dist=" << AdjMat[0][j] << "): ";
        if (AdjMat[0][j] == INF) {
            cout << "Inalcançável\n";
        } else {
            printPath(0, j);
            cout << "\n";
        }
    }
    
    return 0;
}