/* DZY loves chemistry, and he enjoys mixing chemicals.

DZY has n chemicals, and m pairs of them will react. He wants to pour these chemicals into a test tube, and he needs to pour them in one by one, in any order.

Let's consider the danger of a test tube. Danger of an empty test tube is 1. And every time when DZY pours a chemical, if there are already one or more chemicals in the test tube that can react with it, the danger of the test tube will be multiplied by 2. Otherwise the danger remains as it is.

Find the maximum possible danger after pouring all the chemicals one by one in optimal order.
Input

The first line contains two space-separated integers n and m .

Each of the next m lines contains two space-separated integers xi and yi 1 ≤ xi < yi ≤ n. These integers mean that the chemical xi will react with the chemical yi. Each pair of chemicals will appear at most once in the input.

Consider all the chemicals numbered from 1 to n in some order. */

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
    
    int countComponents() {
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (get(i) == i) { 
                components++;
            }
        }
        return components;
    }
};


int main(){
    int n, m;
    cin >> n >> m;

    DSU dsu;
    dsu.init(n);

    while (m--){
        int q1, q2; 
        cin >> q1 >> q2;
        dsu.unite(q1 - 1, q2 - 1);
    }


    int components = dsu.countComponents();
    long long maxDanger = 1LL << (n - components);
    
    cout << maxDanger << endl;

    return 0;
}