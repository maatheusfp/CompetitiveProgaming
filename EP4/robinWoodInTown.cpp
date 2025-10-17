#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int testCases; 
    cin >> testCases;

    while (testCases--){
        int n;
        cin >> n;
        vector<ll> array;

        ll totalSum = 0;

        for (int i = 0; i < n; i++){
            int value; 
            cin >> value;
            array.push_back(value);
            totalSum += value;
        }

        if (n == 1 || n == 2){
            cout << -1 << endl;
            continue;
        }

        sort(array.begin(), array.end());

        int needUnhappy = n / 2 + 1;
        ll criticalWealth = array[needUnhappy - 1];
        
        ll x = max(0LL, 2LL * n * criticalWealth - totalSum + 1);

        cout << x << endl;
    }

    return 0;
}