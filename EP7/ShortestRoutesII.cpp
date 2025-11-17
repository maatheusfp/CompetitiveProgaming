#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

ll AdjMat[505][505];

void floyd_warshall(int V) {
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (AdjMat[i][k] != INF && AdjMat[k][j] != INF) {
                    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
                }
            }
        }
    }
}

int main() {
    
    int n, m, q;
    cin >> n >> m >> q;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                AdjMat[i][j] = 0;
            } else {
                AdjMat[i][j] = INF;
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        AdjMat[a][b] = min(AdjMat[a][b], c);
        AdjMat[b][a] = min(AdjMat[b][a], c);
    }
    
    floyd_warshall(n);
    
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        
        if (AdjMat[a][b] == INF) {
            cout << -1 << endl;
        } else {
            cout << AdjMat[a][b] << endl;
        }
    }
    
    return 0;
}