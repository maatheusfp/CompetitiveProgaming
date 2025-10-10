/* There are nn cities and initially no roads between them. However, every day a new road will be constructed, and there will be a total of mm roads.

A component is a group of cities where there is a route between any two cities using the roads. After each day, your task is to find the number of components and the size of the largest component.
Input

The first input line has two integers nn and mm: the number of cities and roads. The cities are numbered 1,2,…,n1,2,…,n.

Then, there are mm lines describing the new roads. Each line has two integers aa and bb: a new road is constructed between cities aa and bb.

You may assume that every road will be constructed between two different cities.
Output

Print mm lines: the required information after each day.
Constraints

    1≤n≤1051≤n≤105
    1≤m≤2⋅1051≤m≤2⋅105
    1≤a,b≤n1≤a,b≤n */


#include <bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> p, size;
    int n;
    int maxSize;
    int components;
    
    void init(int _n) {
        n = _n;
        p.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;        // Cada elemento é seu próprio pai
            size[i] = 1;     // Cada conjunto tem tamanho 1 inicialmente
        }
        maxSize = 1;
        components = n;
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

        components--;
        if (size[b] > maxSize){
            maxSize = size[b];
        }
    }
    
    bool connected(int a, int b) {
        return get(a) == get(b);
    }

    int getMaxSize(){
        return maxSize;
    }

    int getComponents(){
        return components;
    }
};

int main(){

    int numCity, numRoads;
    cin >> numCity >> numRoads;

    DSU dsu; 
    dsu.init(numCity);

    while (numRoads--){
        int cityA, cityB;
        cin >> cityA >> cityB;

        dsu.unite(cityA - 1, cityB - 1);
        cout << dsu.getComponents() << " " << dsu.getMaxSize() << endl;
    }

    return 0;
}