#include <bits/stdc++.h>
using namespace std;

long long modPow(long long x, long long y, long long n) {
    if (y == 0) return 1;
    
    long long result = 1;
    x = x % n; 
    
    while (y > 0) {
        if (y & 1) {
            result = (result * x) % n;
        }
        
        y = y >> 1; 
        x = (x * x) % n; 
    }
    
    return result;
}

long long modPow_recursive(long long x, long long y, long long n) {
    if (y == 0) return 1;
    
    long long half = modPow_recursive(x, y / 2, n);
    half = (half * half) % n;
    
    if (y % 2 == 1) {
        half = (half * x) % n;
    }
    
    return half;
}

int main() {
    int c;
    cin >> c;
    
    while (c--) {
        long long x, y, n;
        cin >> x >> y >> n;
        
        // Calcula (x^y) mod n
        cout << modPow(x, y, n) << endl;
    }
    
    return 0;
}


// Adição modular (evita overflow)
long long addMod(long long a, long long b, long long mod) {
    return ((a % mod) + (b % mod)) % mod;
}

// Multiplicação modular (evita overflow)
long long mulMod(long long a, long long b, long long mod) {
    return ((a % mod) * (b % mod)) % mod;
}

// Subtração modular (garante resultado positivo)
long long subMod(long long a, long long b, long long mod) {
    return ((a % mod) - (b % mod) + mod) % mod;
}

// Inverso modular usando o Teorema de Fermat
// Funciona apenas se mod é primo
// a^(-1) ≡ a^(mod-2) (mod mod)
long long modInverse(long long a, long long mod) {
    return modPow(a, mod - 2, mod);
}

// Divisão modular (usando inverso modular)
// (a / b) mod m = (a * b^(-1)) mod m
long long divMod(long long a, long long b, long long mod) {
    return mulMod(a, modInverse(b, mod), mod);
}

/*
 * ═══════════════════════════════════════════════════════════════
 * COMPLEXIDADE
 * ═══════════════════════════════════════════════════════════════
 * 
 * modPow: O(log y)
 * - Reduz o expoente pela metade a cada iteração
 * - Muito mais rápido que O(y) da abordagem ingênua
 * 
 * ═══════════════════════════════════════════════════════════════
 * COMPARAÇÃO: Java vs C++
 * ═══════════════════════════════════════════════════════════════
 * 
 * Java:
 * - BigInteger.modPow(y, n) - função built-in
 * - Suporta números arbitrariamente grandes
 * 
 * C++:
 * - Implementação manual necessária
 * - long long suporta até ~9×10^18
 * - Para números maiores: usar __int128 ou bibliotecas externas
 * 
 * ═══════════════════════════════════════════════════════════════
 * APLICAÇÕES
 * ═══════════════════════════════════════════════════════════════
 * 
 * 1. Criptografia (RSA)
 * 2. Hashing
 * 3. Teorema de Fermat
 * 4. Cálculo de grandes potências
 * 5. Combinatória modular
 * 6. Geometria computacional
 */
