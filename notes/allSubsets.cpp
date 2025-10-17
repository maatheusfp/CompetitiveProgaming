#include <bits/stdc++.h>
using namespace std; 
#define ll long long

int main(){
    vector<ll> array = {1, 2, 3};
    int arraySize = array.size();

    for (int i = 0; i < (1 << arraySize); i++){
        for (int j = 0; j < arraySize; j++){
            if ((i & (1 << j)) > 0)
                cout << array[j] << " ";
        }
        cout << endl;
    }

    return 0;
}