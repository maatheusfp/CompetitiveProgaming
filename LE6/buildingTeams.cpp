#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define INF 1000000000

vector<vi> AdjList;
vi color;

bool isBipartite(int s) {
    queue<int> q; 
    q.push(s);
    color[s] = 1; 
    
    while (!q.empty()) { 
        int u = q.front(); 
        q.pop();
        
        for (int v : AdjList[u]) {
            if (color[v] == INF) {
                color[v] = 3 - color[u];
                q.push(v);
            }
            else if (color[v] == color[u]) {
                return false;
            }
        }
    }
    
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;
    
    AdjList.assign(n + 1, vi()); 
    color.assign(n + 1, INF);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        AdjList[a].push_back(b);
        AdjList[b].push_back(a);
    }
    
    bool allBipartite = true;
    
    for (int i = 1; i <= n; i++) {
        if (color[i] == INF) { 
            if (!isBipartite(i)) {
                allBipartite = false;
                break;
            }
        }
    }
    
    if (!allBipartite) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 1; i <= n; i++) {
            cout << color[i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}