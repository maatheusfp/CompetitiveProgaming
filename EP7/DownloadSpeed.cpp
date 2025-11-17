#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

struct Edge {
    int to;
    ll cap;
    int rev;  
};

vector<vector<Edge>> graph;
vector<int> parent, parentEdge;
int V, s, t;

bool bfs() {
    vector<int> dist(V + 1, -1);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    
    parent.assign(V + 1, -1);
    parentEdge.assign(V + 1, -1);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        if (u == t) break;
        
        for (int i = 0; i < (int)graph[u].size(); i++) {
            Edge& e = graph[u][i];
            
            if (e.cap > 0 && dist[e.to] == -1) {
                dist[e.to] = dist[u] + 1;
                parent[e.to] = u;
                parentEdge[e.to] = i;
                q.push(e.to);
            }
        }
    }
    
    return dist[t] != -1;  
}

ll augment() {
    ll flow = INF;
    int v = t;
    
    while (v != s) {
        int u = parent[v];
        int idx = parentEdge[v];
        flow = min(flow, graph[u][idx].cap);
        v = u;
    }
    
    v = t;
    while (v != s) {
        int u = parent[v];
        int idx = parentEdge[v];
        
        graph[u][idx].cap -= flow;  
        graph[v][graph[u][idx].rev].cap += flow;  
        
        v = u;
    }
    
    return flow;
}

void addEdge(int from, int to, ll cap) {
    graph[from].push_back({to, cap, (int)graph[to].size()});
    graph[to].push_back({from, 0, (int)graph[from].size() - 1});
}

ll maxFlow(int source, int sink) {
    s = source;
    t = sink;
    ll mf = 0;
    
    while (bfs()) {
        ll flow = augment();
        mf += flow;
    }
    
    return mf;
}

int main() {
    
    int n, m;
    cin >> n >> m;
    
    V = n;
    graph.assign(n + 1, vector<Edge>());
    
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        addEdge(a, b, c);
    }
    
    ll mf = maxFlow(1, n); 
    
    cout << mf;
    
    return 0;
}