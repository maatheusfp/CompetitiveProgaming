#include <bits/stdc++.h>
using namespace std; 
#define ll long long

bool canDivide(vector<ll>& arr, int k, ll maxSum) {
    int subarrays = 1;
    ll currentSum = 0;
    
    for (ll value : arr) {
        if (value > maxSum) return false;
        
        if (currentSum + value > maxSum) {
            subarrays++;
            currentSum = value;
            if (subarrays > k) return false;
        } else {
            currentSum += value;
        }
    }
    return true;
}

int main(){
    int n, k;
    cin >> n >> k; 

    ll totalSum = 0, maxElement = 0;
    vector<ll> array(n);

    for (int i = 0; i < n; i++){
        cin >> array[i];
        totalSum += array[i];
        maxElement = max(maxElement, array[i]);
    }

    ll left = maxElement, right = totalSum;
    ll answer = right;
    
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        
        if (canDivide(array, k, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << answer << endl;
    return 0;
}