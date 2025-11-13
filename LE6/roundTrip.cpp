#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define UNVISITED -1
#define VISITED 1

vector<vi> AdjList;
vi dfs_num;
vi parent;
int start_cycle = -1, end_cycle = -1;

bool dfs(int u, int par) {
    dfs_num[u] = VISITED;
    parent[u] = par;
    
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        
        if (v == par) continue;
        
        if (dfs_num[v] == VISITED) {
            start_cycle = v;
            end_cycle = u;
            return true;
        }
        
        if (dfs_num[v] == UNVISITED) {
            if (dfs(v, u)) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    AdjList.assign(n + 1, vi());
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        AdjList[a].push_back(b);
        AdjList[b].push_back(a);
    }
    
    dfs_num.assign(n + 1, UNVISITED);
    parent.assign(n + 1, -1);
    
    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (dfs_num[i] == UNVISITED) {
            if (dfs(i, -1)) {
                found = true;
                break;
            }
        }
    }
    
    if (!found) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    vector<int> cycle;
    cycle.push_back(start_cycle);
    
    int current = end_cycle;
    while (current != start_cycle) {
        cycle.push_back(current);
        current = parent[current];
    }
    cycle.push_back(start_cycle);
    
    cout << cycle.size() << "\n";
    for (int city : cycle) {
        cout << city << " ";
    }
    cout << "\n";
    
    return 0;
}