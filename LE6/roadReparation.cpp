#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

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
    cin >> n >> m;
    
    vector<pair<ll, ii>> EdgeList;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;  // Ajusta para índice 0
        EdgeList.push_back(make_pair(c, ii(a, b)));
    }
    
    sort(EdgeList.begin(), EdgeList.end());
    
    ll mst_cost = 0;
    int edges_taken = 0;
    
    DSU dsu;
    dsu.init(n);
    
    for (int i = 0; i < m; i++) {
        ll weight = EdgeList[i].first;
        int u = EdgeList[i].second.first;
        int v = EdgeList[i].second.second;
        
        if (!dsu.connected(u, v)) {
            mst_cost += weight;
            dsu.unite(u, v);
            edges_taken++;
            
            if (edges_taken == n - 1) break;
        }
    }
    
    if (edges_taken == n - 1) {
        cout << mst_cost << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
    
    return 0;
}