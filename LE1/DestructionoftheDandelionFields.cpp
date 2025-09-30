/* Farmer John has a lawnmower, initially turned off. He also has nn fields, with the ii-th field having aiai​ dandelions. He will visit all the fields in any order he wants, and each field exactly once.

FJ's lawnmower seems to have a mind of its own. Right before visiting a field, it checks if the field has an even or odd number of dandelions. If it has an odd number, then the lawnmower toggles its state (if it is off, it turns on; if it is on, it turns off). Then, if the lawnmower is on, it will cut all dandelions in that field. Otherwise, if the lawnmower is off, then FJ will simply visit the field and cut no dandelions.

If FJ visits the nn fields in optimal order, what is the maximum total number of dandelions he can cut?
Input

The first line contains an integer tt (1≤t≤1041≤t≤104) — the number of test cases.

The first line contains an integer nn (1≤n≤2⋅1051≤n≤2⋅105) — the number of fields.

The following line contains nn space-separated integers a1,a2,…,ana1​,a2​,…,an​ (1≤ai≤1091≤ai​≤109) — the number of dandelions in each field.

It is guaranteed that the sum of nn over all test cases does not exceed 2⋅1052⋅105.
Output

For each test case, output an integer on a new line: maximum dandelions FJ can cut if he visits all nn fields in optimal order. */

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm> 
using namespace std;

bool IsPar(long long n){
    if (n % 2 == 0)
        return true; 
    
    return false;
}

long long somaValorArray(vector<long long> &impares, int indiceFinal){
    long long soma = 0;
    for (int i = 0; i < indiceFinal; i++)
        soma += impares[i];
    
    return soma;
}

long long CalculaTotal(long long valorInicial, vector<long long> &impares){
    if (impares.size() < 1)
        return 0;
    
    sort(impares.begin(), impares.end(), greater<long long>());
    return valorInicial + somaValorArray(impares, ceil(impares.size()/2.0));
}

int main(){
    int testes;
    cin >> testes;

    for (int i = 0; i < testes; i++){
        int campos;
        cin >> campos;

        long long soma = 0;
        vector<long long> impares; 

        for (int j = 0; j < campos; j++){
            long long quantidadesGirassois = 0;
            cin >> quantidadesGirassois;

            if (IsPar(quantidadesGirassois))
                soma += quantidadesGirassois;
            
            else 
                impares.push_back(quantidadesGirassois);
        }
        
        cout << CalculaTotal(soma, impares) << endl;
    }

    return 0;
}