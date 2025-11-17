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
    printPath(p[u], p, s);
    cout << " -> " << u;
}

// Variante: para quando só precisa do caminho s -> t
void dijkstra_single_pair(int s, int t) {
    int V = AdjList.size();
    vi dist(V, INF);
    vi p(V, -1);
    
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0, s));
    
    while (!pq.empty()) {
        ii front = pq.top();
        pq.pop();
        
        int d = front.first;
        int u = front.second;
        
        if (d > dist[u]) continue;
        
        // OTIMIZAÇÃO: para quando chegar no destino
        if (u == t) break;
        
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                p[v.first] = u;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }
    
    // Imprime apenas o caminho s -> t
    cout << "Menor caminho de " << s << " até " << t << ":\n";
    if (dist[t] == INF) {
        cout << "Não existe caminho!\n";
    } else {
        cout << "Distância: " << dist[t] << "\n";
        cout << "Caminho: ";
        printPath(t, p, s);
        cout << "\n";
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
    }
    
    int s, t;
    cout << "Origem e destino: ";
    cin >> s >> t;
    
    dijkstra_single_pair(s, t);
    
    return 0;
}