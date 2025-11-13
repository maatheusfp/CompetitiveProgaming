#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

vector<vii> AdjList;

void printPath(int u, vi& p, int s) {
    if (u == s) {
        cout << s;
        return;
    }
    if (p[u] == -1) {
        cout << "?";
        return;
    }
    printPath(p[u], p, s);
    cout << " -> " << u;
}

bool bellman_ford(int s) {
    int V = AdjList.size();
    vi dist(V, INF);
    vi p(V, -1);
    
    dist[s] = 0;
    
    // Relaxa TODAS as arestas V-1 vezes
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            if (dist[u] == INF) continue; // otimização: pula vértices inalcançáveis
            
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                
                // Relaxação simples
                if (dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second;
                    p[v.first] = u;
                }
            }
        }
    }
    
    // DETECÇÃO DE CICLO NEGATIVO
    // Se ainda conseguir relaxar após V-1 iterações, há ciclo negativo
    bool hasNegativeCycle = false;
    for (int u = 0; u < V; u++) {
        if (dist[u] == INF) continue;
        
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            
            if (dist[u] + v.second < dist[v.first]) {
                hasNegativeCycle = true;
                cout << "AVISO: Ciclo negativo detectado!\n";
                cout << "O grafo contém ciclo negativo alcançável da origem.\n";
                return false;
            }
        }
    }
    
    // Imprime resultados
    cout << "Distâncias (Bellman-Ford):\n";
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        if (dist[i] == INF) {
            cout << "INF\n";
        } else {
            cout << dist[i] << " | Caminho: ";
            printPath(i, p, s);
            cout << "\n";
        }
    }
    
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    AdjList.assign(n, vii());
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        AdjList[u].push_back(ii(v, w));
    }
    
    int s;
    cin >> s;
    
    bellman_ford(s);
    
    return 0;
}