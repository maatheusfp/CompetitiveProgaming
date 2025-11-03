#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;   // par (vértice, peso)
typedef vector<ii> vii;       // vetor de pares
typedef vector<int> vi;       // vetor de inteiros

#define UNVISITED -1
#define VISITED 1

vector<vii> AdjList;          // lista de adjacência com pesos
vi dfs_num;                   // marca vértices visitados

void dfs(int u) {
    dfs_num[u] = VISITED;     // marca como visitado
    
    // percorre todos os vizinhos de u
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j]; // v é um par (vizinho, peso)
        
        // se o vizinho não foi visitado
        if (dfs_num[v.first] == UNVISITED) {
            dfs(v.first);     // visita recursivamente
        }
        // v.second contém o peso da aresta (ignorado em travessia simples)
    }
}

int main(){
    int n, m; // n = vértices, m = arestas
    cin >> n >> m;
    
    // inicializa a lista de adjacência
    AdjList.assign(n, vii());
    
    // lê as arestas
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; // u->v com peso w
        AdjList[u].push_back(ii(v, w));
        // AdjList[v].push_back(ii(u, w)); // descomente para grafo não-direcionado
    }
    
    // inicializa todos como UNVISITED
    dfs_num.assign(n, UNVISITED);
    
    // executa DFS a partir do vértice 0
    dfs(0);
    
    return 0;
}