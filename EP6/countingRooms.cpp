#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;

vector<string> mapa;
vector<vector<bool>> visited;

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && 
           mapa[x][y] == '.' && !visited[x][y];
}

void dfs(int x, int y) {
    visited[x][y] = true;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (isValid(nx, ny)) {
            dfs(nx, ny);
        }
    }
}


int main(){
    cin >> n >> m;

    mapa.resize(n);
    visited.assign(n, vector<bool>(m, false));
    
    for(int i = 0; i < n; i++){
        cin >> mapa[i];
    }
    
    int rooms = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mapa[i][j] == '.' && !visited[i][j]){
                dfs(i, j);
                rooms++; 
            }
        }
    }
    
    cout << rooms << endl;

    return 0;
}




