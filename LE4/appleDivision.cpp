#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int applesNum;
    cin >> applesNum;

    ll minDiff = LLONG_MAX;

    ll totalSum = 0;
    vector<ll> array;

    for (int i = 0; i < applesNum; i++){
        int value;
        cin >> value;

        totalSum += value;
        array.push_back(value);
    }

    for (int i = 0; i < (1 << array.size()); i++){
        ll firstGroupSum = 0;
        for (int j = 0; j < array.size(); j++){
            if ((i & (1 << j)))
                firstGroupSum += array[j];
        }
        ll diff = sqrt((pow((totalSum - firstGroupSum) - firstGroupSum, 2)));
        if (diff < minDiff)
            minDiff = diff;
    }

    cout << minDiff << endl;


    return 0;
}