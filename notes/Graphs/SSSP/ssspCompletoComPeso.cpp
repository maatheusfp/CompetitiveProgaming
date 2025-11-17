#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

vector<vii> AdjList;

// Reconstrói o caminho de s até u recursivamente
void printPath(int u, vi& p, int s) {
    if (u == s) {
        cout << s;
        return;
    }
    printPath(p[u], p, s);
    cout << " -> " << u;
}

void dijkstra_sssp(int s) {
    int V = AdjList.size();
    vi dist(V, INF);
    vi p(V, -1);  // vetor de pais/predecessores
    
    dist[s] = 0;
    
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0, s));
    
    while (!pq.empty()) {
        ii front = pq.top();
        pq.pop();
        
        int d = front.first;
        int u = front.second;
        
        // Lazy Deletion: ignora cópias antigas
        if (d > dist[u]) continue;
        
        // Relaxa todas as arestas
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                p[v.first] = u;  // ADICIONA: armazena o pai
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }
    
    // Imprime distâncias E caminhos
    cout << "Distâncias e caminhos a partir do vértice " << s << ":\n";
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        if (dist[i] == INF) {
            cout << "INF (inalcançável)\n";
        } else {
            cout << dist[i] << " | Caminho: ";
            printPath(i, p, s);
            cout << "\n";
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    AdjList.assign(n, vii());
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        AdjList[u].push_back(ii(v, w));
        // AdjList[v].push_back(ii(u, w)); // descomente para não-direcionado
    }
    
    int s;
    cin >> s;
    
    dijkstra_sssp(s);
    
    return 0;
}