#include <bits/stdc++.h>
using namespace std;

vector<long long> generatePrimes(int count) {
    vector<long long> primes;
    primes.push_back(2);
    
    long long candidate = 3;
    while (primes.size() < count) {
        bool isPrime = true;
        for (long long p : primes) {
            if (p * p > candidate) break;
            if (candidate % p == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primes.push_back(candidate);
        }
        candidate += 2;
    }
    
    return primes;
}

int main() {
    
    vector<long long> primes = generatePrimes(400005);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        sort(a.begin(), a.end());
        
        long long coins = 0;
        int primeIdx = 0;
        int removed = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            if (primeIdx >= primes.size()) {
                removed++;
                continue;
            }
            
            if (a[i] > primes[primeIdx]) {
                coins += a[i] - primes[primeIdx];
                primeIdx++;
            }
            else {
                long long cost = primes[primeIdx] - a[i];
                
                if (cost > coins) {
                    removed++;
                }
                else {
                    coins -= cost;
                    primeIdx++;
                }
            }
        }
        
        cout << removed << endl;
    }
    
    return 0;
}

