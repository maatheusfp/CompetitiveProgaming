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

int main(){
    int n, m;
    
    while(cin >> n >> m && (n || m)) {
        vector<pair<int, ii>> EdgeList;
        
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            EdgeList.push_back(make_pair(w, ii(u, v)));
        }
        
        sort(EdgeList.begin(), EdgeList.end());
        
        DSU dsu;
        dsu.init(n);
        
        int max_range = 0;
        int edges_taken = 0;
        
        for (int i = 0; i < m; i++) {
            int weight = EdgeList[i].first;
            int u = EdgeList[i].second.first;
            int v = EdgeList[i].second.second;
            
            if (!dsu.connected(u, v)) {
                dsu.unite(u, v);
                max_range = max(max_range, weight);                 
                edges_taken++;
                
                if (edges_taken == n - 1) break;
            }
        }
        
        if (edges_taken == n - 1) {
            cout << max_range << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    
    return 0;
}