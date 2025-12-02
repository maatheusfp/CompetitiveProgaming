#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long stringToMod(const string& s) {
    long long result = 0;
    for (char c : s) {
        int digit = c - '0';
        result = (result * 10 + digit) % MOD;
    }
    return result;
}

long long modPow(long long x, long long y) {
    if (y == 0) return 1;
    long long result = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1) {
            result = (result * x) % MOD;
        }
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return result;
}

long long addMod(long long a, long long b) {
    return (a + b) % MOD;
}

long long subMod(long long a, long long b) {
    return ((a - b) % MOD + MOD) % MOD;
}

long long mulMod(long long a, long long b) {
    return (a * b) % MOD;
}

int main() {
    string x_str, y_str;
    char op;
    
    cin >> x_str >> op >> y_str;
    
    long long x = stringToMod(x_str);
    long long y = stringToMod(y_str);
    
    long long result;
    
    if (op == '+') {
        result = addMod(x, y);
    } else if (op == '-') {
        result = subMod(x, y);
    } else if (op == '*') {
        result = mulMod(x, y);
    } else if (op == '^') {
        y = 0;
        for (char c : y_str) {
            int digit = c - '0';
            y = (y * 10 + digit) % (MOD - 1);
        }
        result = modPow(x, y);
    }
    
    cout << result << endl;
    
    return 0;
}
