#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll calculateNecessaryWaterByHeight(vector<ll> &coral, ll h){
    ll totalWater = 0;
    for (int height : coral){
        if (height < h)
            totalWater += (h - height);
    }
    return totalWater;
}

int main(){
    int testCases; 
    cin >> testCases;

    while (testCases--){
        int arraySize;
        ll  unitesOfWater;
        cin >> arraySize >> unitesOfWater;
        vector<ll> coral; 

        for (int i = 0; i < arraySize; i++){
            int value; 
            cin >> value;

            coral.push_back(value);
        }

        ll left = 1, right = 2e9;
        ll maxHeight = 1;

        while (left <= right){
            ll mid = left + (right - left) / 2;

            if (calculateNecessaryWaterByHeight(coral, mid) <= unitesOfWater){
                maxHeight = mid;
                left = mid + 1;
            }
            else 
                right = mid - 1;
        }

        cout << maxHeight << endl;

    }
    
    return 0;
}