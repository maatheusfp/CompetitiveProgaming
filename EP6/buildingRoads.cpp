#include <bits/stdc++.h>
using namespace std;

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
    
    DSU dsu;
    dsu.init(n + 1);
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dsu.unite(a, b);
    }
    
    vector<int> new_roads;
    int first_component = -1;
    
    for(int i = 1; i <= n; i++) {
        int rep = dsu.get(i);
        
        if(first_component == -1) {
            first_component = i; 
        } else if(!dsu.connected(first_component, i)) {
            new_roads.push_back(i);
            dsu.unite(first_component, i);
        }
    }
    
    cout << new_roads.size() << endl;
    
    for(int city : new_roads) {
        cout << first_component << " " << city << endl;
    }
    
    return 0;
}