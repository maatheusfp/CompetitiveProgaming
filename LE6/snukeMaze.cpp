#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

#define UNVISITED -1
#define VISITED 1

int H, W;
vector<string> grid;
string pattern = "snuke";
int dfs_num[500][500][5]; 

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool dfs(int x, int y, int pos) {
    dfs_num[x][y][pos] = VISITED;
    
    if (x == H-1 && y == W-1) {
        return true;
    }
    
    int nextPos = (pos + 1) % 5;
    char nextChar = pattern[nextPos];
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
            if (dfs_num[nx][ny][nextPos] == UNVISITED && 
                grid[nx][ny] == nextChar) {
                
                if (dfs(nx, ny, nextPos)) {
                    return true;  
                }
            }
        }
    }
    
    return false;  
}

int main() {
    cin >> H >> W;
    
    grid.resize(H);
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }
    
    memset(dfs_num, UNVISITED, sizeof(dfs_num));
    
    if (grid[0][0] == 's') {
        if (dfs(0, 0, 0)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}