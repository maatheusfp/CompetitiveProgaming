#include <bits/stdc++.h>
using namespace std;


double solve(int dice_left, int score, int a, int b, vector<vector<double>>& dp, vector<vector<bool>>& visited) {

    if (dice_left == 0) {
        if (score >= a && score <= b) 
            return 1; 

        return 0; 
    }
    
    if (score > b) 
        return 0;
    
    if (visited[dice_left][score]) 
        return dp[dice_left][score];
    
    visited[dice_left][score] = true;
    double ways = 0;
    
    for (int face = 1; face <= 6; face++) 
        ways += solve(dice_left - 1, score + face, a, b, dp, visited);
    
    return dp[dice_left][score] = ways;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    
    vector<vector<double>> dp(n + 1, vector<double>(6 * n + 1, 0.0));
    vector<vector<bool>> visited(n + 1, vector<bool>(6 * n + 1, false));
    
    double favorable_events = solve(n, 0, a, b, dp, visited);
    
    double total_space = pow(6, n);
    
    double probability = favorable_events / total_space;
    
    cout << fixed << setprecision(6) << probability << endl;
    
    return 0;
}

