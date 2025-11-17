#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

vector<vii> AdjList;

bool isBipartite(int s) {
    queue<int> q; 
    q.push(s);
    
    vi color(AdjList.size(), INF); // INF = não colorido ainda
    color[s] = 0;                  // colore s com cor 0 (início)
    
    bool isBipartite = true;
    
    while (!q.empty() && isBipartite) { 
        int u = q.front(); 
        q.pop();
        
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            
            // CASO 1: vizinho ainda não foi colorido
            if (color[v.first] == INF) {
                // colore com a cor OPOSTA de u
                color[v.first] = 1 - color[u]; // se u=0 então v=1, se u=1 então v=0
                q.push(v.first);
            }
            // CASO 2: vizinho já foi colorido
            else if (color[v.first] == color[u]) {
                // CONFLITO! dois vértices adjacentes tem a mesma cor
                isBipartite = false; 
                break;
            }
            // CASO 3 (implícito): vizinho tem cor diferente = OK!
        }
    }
    
    return isBipartite;
}

int main(){
    int n, m;
    cin >> n >> m;
    
    AdjList.assign(n, vii());
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        AdjList[u].push_back(ii(v, w));
        AdjList[v].push_back(ii(u, w)); // grafo não-direcionado
    }
    
    // verifica se cada componente conectado é bipartido
    vi color(n, INF);
    bool allBipartite = true;
    
    for (int i = 0; i < n; i++) {
        if (color[i] == INF) { // nova componente
            if (!isBipartite(i)) {
                allBipartite = false;
                cout << "Componente iniciando em " << i << " NÃO é bipartido\n";
            } else {
                cout << "Componente iniciando em " << i << " é bipartido\n";
            }
        }
    }
    
    if (allBipartite) {
        cout << "\nO grafo inteiro é BIPARTIDO!\n";
    } else {
        cout << "\nO grafo NÃO é bipartido\n";
    }
    
    return 0;
}