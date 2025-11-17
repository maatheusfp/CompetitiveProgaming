#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define UNVISITED -1

vector<vii> AdjList;
vi dfs_num; // agora armazena o número do componente

void dfs(int u, int componentNum) {
    dfs_num[u] = componentNum; // atribui número do componente
    
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        
        if (dfs_num[v.first] == UNVISITED) {
            dfs(v.first, componentNum);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    
    AdjList.assign(n, vii());
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        AdjList[u].push_back(ii(v, w));
        AdjList[v].push_back(ii(u, w));
    }
    
    // encontra todos os componentes conectados
    int numCC = 0;
    dfs_num.assign(n, UNVISITED);
    
    for (int i = 0; i < n; i++) {
        if (dfs_num[i] == UNVISITED) {
            dfs(i, numCC); // atribui número do componente
            numCC++;
        }
    }
    
    cout << "Total de componentes: " << numCC << "\n";
    
    // agora podemos verificar múltiplos pares rapidamente
    int q; // número de consultas
    cin >> q;
    
    while (q--) {
        int x, y;
        cin >> x >> y;
        
        if (dfs_num[x] == dfs_num[y]) {
            cout << x << " e " << y << " estão no mesmo componente\n";
        } else {
            cout << x << " e " << y << " estão em componentes diferentes\n";
        }
    }
    
    return 0;
}