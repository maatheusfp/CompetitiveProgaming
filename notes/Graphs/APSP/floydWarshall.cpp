#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int AdjMat[405][405];  // suporta até 400 vértices

void floyd_warshall(int V) {
    // O algoritmo mais curto: apenas 3 loops aninhados!
    // ORDEM IMPORTANTE: k -> i -> j
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
}

int main() {
    int V, E;
    cin >> V >> E;
    
    // Inicializa matriz com INF
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) AdjMat[i][j] = 0;  // distância para si mesmo
            else AdjMat[i][j] = INF;
        }
    }
    
    // Lê as arestas
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        AdjMat[u][v] = w;
        // AdjMat[v][u] = w;  // descomente para grafo não-direcionado
    }
    
    // Executa Floyd-Warshall
    floyd_warshall(V);
    
    // Imprime matriz de distâncias
    cout << "\nMatriz de menores distâncias:\n";
    cout << "    ";
    for (int j = 0; j < V; j++) cout << setw(4) << j;
    cout << "\n";
    
    for (int i = 0; i < V; i++) {
        cout << setw(3) << i << ":";
        for (int j = 0; j < V; j++) {
            if (AdjMat[i][j] == INF)
                cout << " INF";
            else
                cout << setw(4) << AdjMat[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}