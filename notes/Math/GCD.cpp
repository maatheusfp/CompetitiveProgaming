#include <bits/stdc++.h>
using namespace std;


long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long gcd_iterative(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int main() {
    int N;
    cin >> N;
    
    while (N--) {
        long long p, q;
        char ch; 
        
        cin >> p >> ch >> q;
        
        long long gcd_pq = gcd(p, q);
        
        p /= gcd_pq;
        q /= gcd_pq;
        
        cout << p << " / " << q << endl;
    }
    
    return 0;
}
