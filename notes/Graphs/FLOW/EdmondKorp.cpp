#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

struct Edge {
    int to, cap, rev;  // destino, capacidade, índice da aresta reversa
};

vector<vector<Edge>> graph;
vector<int> parent, parentEdge;
int V, s, t;

int bfs() {
    vector<int> dist(V, -1);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    
    parent.assign(V, -1);
    parentEdge.assign(V, -1);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        if (u == t) break;
        
        for (int i = 0; i < graph[u].size(); i++) {
            Edge& e = graph[u][i];
            
            if (e.cap > 0 && dist[e.to] == -1) {
                dist[e.to] = dist[u] + 1;
                parent[e.to] = u;
                parentEdge[e.to] = i;
                q.push(e.to);
            }
        }
    }
    
    return dist[t] != -1;  // retorna se alcançou t
}

int augment() {
    // Encontra capacidade mínima no caminho
    int flow = INF;
    int v = t;
    
    while (v != s) {
        int u = parent[v];
        int idx = parentEdge[v];
        flow = min(flow, graph[u][idx].cap);
        v = u;
    }
    
    // Atualiza capacidades
    v = t;
    while (v != s) {
        int u = parent[v];
        int idx = parentEdge[v];
        
        graph[u][idx].cap -= flow;  // forward edge
        graph[v][graph[u][idx].rev].cap += flow;  // backward edge
        
        v = u;
    }
    
    return flow;
}

void addEdge(int from, int to, int cap) {
    graph[from].push_back({to, cap, (int)graph[to].size()});
    graph[to].push_back({from, 0, (int)graph[from].size() - 1});
    // aresta reversa começa com capacidade 0
}

int maxFlow(int source, int sink) {
    s = source;
    t = sink;
    int mf = 0;
    
    while (bfs()) {
        int flow = augment();
        mf += flow;
    }
    
    return mf;
}

void printFlow() {
    cout << "\nFluxo nas arestas:\n";
    for (int u = 0; u < V; u++) {
        for (Edge& e : graph[u]) {
            if (e.cap == 0 && e.to != s) {  // aresta usada
                // Encontra capacidade original
                int origCap = graph[e.to][e.rev].cap;
                cout << u << " -> " << e.to << ": " << origCap << "\n";
            }
        }
    }
}

int main() {
    int E;
    cin >> V >> E;
    
    graph.assign(V, vector<Edge>());
    
    for (int i = 0; i < E; i++) {
        int u, v, cap;
        cin >> u >> v >> cap;
        addEdge(u, v, cap);
    }
    
    cin >> s >> t;
    
    int mf = maxFlow(s, t);
    
    cout << "\nFluxo Máximo: " << mf << "\n";
    printFlow();
    
    return 0;
}