#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;   // (distância, vértice)
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

vector<vii> AdjList;

void dijkstra(int s) {
    int V = AdjList.size();
    vi dist(V, INF);
    
    dist[s] = 0;
    
    // Priority queue: (distância, vértice)
    // greater<ii> faz o menor ficar no topo
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0, s));
    
    while (!pq.empty()) {
        ii front = pq.top();
        pq.pop();
        
        int d = front.first;   // distância
        int u = front.second;  // vértice
        
        // Lazy Deletion: ignora se já encontrou caminho melhor
        if (d > dist[u]) continue;
        
        // Relaxa todas as arestas saindo de u
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];  // v.first = vizinho, v.second = peso
            
            // Se encontrou caminho melhor
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }
    
    // Imprime distâncias
    cout << "Distâncias a partir do vértice " << s << ":\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) 
            cout << i << ": INF\n";
        else 
            cout << i << ": " << dist[i] << "\n";
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
    
    dijkstra(s);
    
    return 0;
}