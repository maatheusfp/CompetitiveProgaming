#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){

    int X, N;
    cin >> X >> N;

    vector<pair<int, ll>> uber(N);
    for (int i =0; i < N; i++)
        cin >> uber[i].first >> uber[i].second;

    vector<ll> dp(X + 1, LLONG_MAX);
    dp[0] = 0;

    for (int j = 0; j < N; j++){
        int max_passageiros = uber[j].first;
        ll valor = uber[j].second;
        
        for (int i = X; i >= 0; i--){
            if (dp[i] == LLONG_MAX) continue;
            
            for (int passageiros = 1; passageiros <= max_passageiros; passageiros++){
                int proxima_pessoa = i + passageiros;
                if (proxima_pessoa <= X) 
                    dp[proxima_pessoa] = min(dp[proxima_pessoa], dp[i] + valor);
            }
        }
    }

    if (dp[X] == LLONG_MAX)
        cout << -1 << endl;
    else 
        cout << dp[X] << endl;
}