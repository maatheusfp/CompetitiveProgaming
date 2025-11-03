#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

struct DSU{
    vector<int> p, size;
    int n;
    
    void init(int _n) {
        n = _n;
        p.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
            size[i] = 1;
        }
    }
    
    int get(int a) {
        if (p[a] != a) {
            p[a] = get(p[a]);
        }
        return p[a];
    }
    
    void unite(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b) return;
        
        if (size[a] > size[b]) {
            swap(a, b);
        }
        p[a] = b;
        size[b] += size[a];
    }
    
    bool connected(int a, int b) {
        return get(a) == get(b);
    }
};

struct MSTResult {
    int cost;
    int edges_taken;
    vector<pair<int, ii>> edges;
    bool is_connected;
};

MSTResult minimumSpanningSubgraph(int V, vector<pair<int, ii>>& EdgeList, 
                                   vector<pair<int, ii>>& FixedEdges) {
    MSTResult result;
    result.cost = 0;
    result.edges_taken = 0;
    result.is_connected = false;
    
    DSU dsu;
    dsu.init(V);
    
    set<pair<int, int>> fixed_edges_set;
    
    // PASSO 1: Processa arestas FIXADAS
    cout << "\n=== Processando arestas fixadas ===\n";
    for (auto edge : FixedEdges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        
        result.cost += weight;
        dsu.unite(u, v);
        result.edges.push_back(edge);
        result.edges_taken++;
        
        fixed_edges_set.insert({min(u, v), max(u, v)});
        
        cout << "Aresta fixada: " << u << " -- " << v << " (peso: " << weight << ")\n";
    }
    
    if (FixedEdges.size() > 0) {
        cout << "Custo inicial: " << result.cost << "\n";
    }
    
    // PASSO 2: Filtra arestas livres
    vector<pair<int, ii>> FreeEdges;
    for (auto edge : EdgeList) {
        int u = edge.second.first;
        int v = edge.second.second;
        pair<int, int> normalized = {min(u, v), max(u, v)};
        
        if (fixed_edges_set.find(normalized) == fixed_edges_set.end()) {
            FreeEdges.push_back(edge);
        }
    }
    
    // PASSO 3: Ordena arestas livres
    sort(FreeEdges.begin(), FreeEdges.end());
    
    // PASSO 4: Kruskal nas arestas livres
    cout << "\n=== Processando arestas livres (Kruskal) ===\n";
    for (auto edge : FreeEdges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        
        if (!dsu.connected(u, v)) {
            result.cost += weight;
            dsu.unite(u, v);
            result.edges.push_back(edge);
            result.edges_taken++;
            
            cout << "Adicionando: " << u << " -- " << v << " (peso: " << weight << ")\n";
            
            if (result.edges_taken == V - 1) {
                result.is_connected = true;
                break;
            }
        }
    }
    
    if (result.edges_taken >= V - 1) {
        result.is_connected = true;
    }
    
    return result;
}

int main(){
    int V, E;
    cin >> V >> E;
    
    vector<pair<int, ii>> EdgeList;
    
    cout << "Digite as arestas (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        EdgeList.push_back(make_pair(w, ii(u, v)));
    }
    
    int F;
    cout << "\nNúmero de arestas fixadas: ";
    cin >> F;
    
    vector<pair<int, ii>> FixedEdges;
    
    if (F > 0) {
        cout << "Digite as arestas fixadas (u v w):\n";
        for (int i = 0; i < F; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            FixedEdges.push_back(make_pair(w, ii(u, v)));
        }
    }
    
    // Chama a função MST
    MSTResult result = minimumSpanningSubgraph(V, EdgeList, FixedEdges);
    
    // Imprime resultado
    cout << "\n========================================\n";
    cout << "'Minimum' Spanning Subgraph cost = " << result.cost << "\n";
    cout << "Total de arestas: " << result.edges_taken << "\n";
    
    if (result.is_connected) {
        cout << "Status: Grafo CONECTADO!\n";
    } else {
        cout << "Status: Grafo DESCONECTADO!\n";
        cout << "Componentes: " << (V - result.edges_taken) << "\n";
    }
    
    cout << "\nArestas do Spanning Subgraph:\n";
    for (auto edge : result.edges) {
        cout << edge.second.first << " -- " << edge.second.second 
             << " (peso: " << edge.first << ")\n";
    }
    
    return 0;
}