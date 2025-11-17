#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> C(n, vector<int>(n));
    vector<vector<int>> dist(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> C[i][j];
            dist[i][j] = C[i][j];
        }
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] < C[i][j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    int redundant = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { 
            if (i == j) continue;
            
            bool canRemove = false;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    if (C[i][k] + C[k][j] == C[i][j]) {
                        canRemove = true;
                        break;
                    }
                }
            }
            
            if (canRemove) {
                redundant++;
            }
        }
    }
    
    cout << redundant << endl;
    
    return 0;
}