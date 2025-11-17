#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
typedef vector<pair<int, ll>> vpil;
typedef vector<ll> vll;

const ll INF = 1e18;


void dijkstra_sssp(int s, vector<vpil> &AdjList) {
    int V = AdjList.size();
    vll dist(V, INF);
    
    dist[s] = 0;
    
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push(pli(0, s));
    
    while (!pq.empty()) {
        pli front = pq.top();
        pq.pop();
        
        ll d = front.first;
        int u = front.second;
        
        if (d > dist[u]) continue;
        
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            auto v = AdjList[u][j];
            
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                pq.push(pli(dist[v.first], v.first));
            }
        }
    }
    
    for (int i = 1; i < V; i++) {
        cout << dist[i];
        if (i < V - 1) cout << " ";
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vpil> AdjList;
    
    AdjList.assign(n + 1, vpil());
    
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        AdjList[u].push_back({v, w});
    }
    
    dijkstra_sssp(1, AdjList);
    
    return 0;
}