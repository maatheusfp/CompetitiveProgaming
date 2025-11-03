#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;   // par (vértice, peso)
typedef vector<ii> vii;       // vetor de pares
typedef vector<int> vi;       // vetor de inteiros

#define INF 1000000000

vector<vii> AdjList;          // lista de adjacência com pesos

void bfs(int s) {
    vi d(AdjList.size(), INF); // distância de s para todos os vértices
    d[s] = 0;                  // distância da fonte para ela mesma é 0
    
    queue<int> q;
    q.push(s);                 // começa pela fonte
    
    while (!q.empty()) {
        int u = q.front(); 
        q.pop();               // queue: camada por camada!
        
        // percorre todos os vizinhos de u
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j]; // v é um par (vizinho, peso)
            
            // se v.first não foi visitado e é alcançável
            if (d[v.first] == INF) {
                d[v.first] = d[u] + 1; // marca como visitado e atualiza distância
                q.push(v.first);       // enfileira para a próxima iteração
            }
            // v.second contém o peso da aresta (ignorado em BFS simples)
        }
    }
    
    // opcional: imprime as distâncias
    cout << "Distâncias a partir do vértice " << s << ":\n";
    for (int i = 0; i < (int)d.size(); i++) {
        if (d[i] == INF) cout << i << ": INF\n";
        else cout << i << ": " << d[i] << "\n";
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
    
    int s; // vértice de origem
    cin >> s;
    
    // executa BFS a partir do vértice s
    bfs(s);
    
    return 0;
}