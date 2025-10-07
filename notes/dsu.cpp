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
            p[i] = i;        // Cada elemento é seu próprio pai
            size[i] = 1;     // Cada conjunto tem tamanho 1 inicialmente
        }
    }
    
    int get(int a) {
        if (p[a] != a) {
            p[a] = get(p[a]);  // Path compression
        }
        return p[a];
    }
    
    void unite(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b) return;  // Já estão no mesmo conjunto
        
        if (size[a] > size[b]) {
            swap(a, b);      // Garante que 'a' seja o menor
        }
        p[a] = b;            // Liga o menor ao maior
        size[b] += size[a];  // Atualiza o tamanho
    }
    
    bool connected(int a, int b) {
        return get(a) == get(b);
    }
};

int main(){
    DSU dsu;
    dsu.init(6);  // Inicializa com 6 elementos
    
    // Exemplo de uso
    dsu.unite(0, 1);
    dsu.unite(2, 3);
    dsu.unite(1, 3);
    
    cout << "0 e 3 conectados? " << (dsu.connected(0, 3) ? "Sim" : "Não") << endl;
    cout << "0 e 4 conectados? " << (dsu.connected(0, 4) ? "Sim" : "Não") << endl;
    
    return 0;
}