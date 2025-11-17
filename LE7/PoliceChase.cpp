#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, m;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});
    
    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
        
        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    
    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n + 1);
    int new_flow;
    
    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    
    return flow;
}

void findMinCut(int s) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (!visited[v] && capacity[u][v] > 0) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    

    vector<pair<int, int>> cutEdges;
    for (int u = 1; u <= n; u++) {
        if (visited[u]) {
            for (int v : adj[u]) {
                if (!visited[v] && capacity[u][v] == 0) {
                    cutEdges.push_back({u, v});
                }
            }
        }
    }
    
    cout << cutEdges.size() << "\n";
    for (auto [u, v] : cutEdges) {
        cout << u << " " << v << "\n";
    }
}

int main() {
    cin >> n >> m;
    
    capacity.assign(n + 1, vector<int>(n + 1, 0));
    adj.assign(n + 1, vector<int>());
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        capacity[a][b] = 1; 
        capacity[b][a] = 1; 
    }
    
    int minCut = maxflow(1, n);
    
    findMinCut(1);
    
    return 0;
}