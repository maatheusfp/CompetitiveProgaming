#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int cases;
    
    cin >> cases;
    
    while(cases--){
        int fields;
        
        cin >> fields;
        
        ll even = 0;
        vector<int> odd;
        
        int dandelions;
        
        
        for(int i=0; i < fields; i++){
            
            cin >> dandelions;
            
            if(dandelions % 2 == 0) even += dandelions;
            else odd.push_back(dandelions);
            
        }
        
        sort(odd.begin(),odd.end(),greater<int>());
        
        ll sum = 0;
        
        if(odd.size() != 0){
            
            sum += even;
            
            int size = odd.size();
            
            int l = 0;
            int r = size - 1;
            
            while (l <= r){
                
                sum += odd[l];
                
                l++; r--;
            }
            
        }
        
        cout << sum << endl;
        
    }
    return 0;
}