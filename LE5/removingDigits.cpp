#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int maiorDigito(ll num){
    int maior = 0;
    while (num > 0){
        maior = max(maior, (int)(num % 10));
        num /= 10;
    }
    return maior;
}

int main(){

    ll n; 
    cin >> n;
    ll passos = 0;
    while (n > 0){
        n -= maiorDigito(n);
        passos++;
    }

    cout << passos << endl;

    return 0;
}