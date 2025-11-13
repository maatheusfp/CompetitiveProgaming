#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

vector<vii> AdjList;

// Função para imprimir o caminho de s até u
void printPath(int u, vi& p, int s) {
    if (u == s) {
        cout << s;
        return;
    }
    printPath(p[u], p, s);
    cout << " -> " << u;
}

void bfs_sssp(int s) {
    vi dist(AdjList.size(), INF);
    vi p(AdjList.size(), -1);  // vetor de pais/predecessores
    
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            
            if (dist[v.first] == INF) {
                dist[v.first] = dist[u] + 1;
                p[v.first] = u;  // CHAVE: armazena o pai
                q.push(v.first);
            }
        }
    }
    
    // Imprime distâncias
    cout << "Distâncias a partir do vértice " << s << ":\n";
    for (int i = 0; i < (int)dist.size(); i++) {
        cout << i << ": ";
        if (dist[i] == INF) {
            cout << "INF\n";
        } else {
            cout << dist[i] << " | Caminho: ";
            printPath(i, p, s);
            cout << "\n";
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    
    AdjList.assign(n, vii());
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // Grafo não-ponderado: peso sempre 1
        AdjList[u].push_back(ii(v, 1));
        // AdjList[v].push_back(ii(u, 1)); // descomente para não-direcionado
    }
    
    int s;
    cin >> s;
    
    bfs_sssp(s);
    
    return 0;
}