/* You are given a list of nn integers, and your task is to calculate the number of distinct values in the list.
Input

The first input line has an integer nn: the number of values.

The second line has nn integers x1,x2,…,xnx1​,x2​,…,xn​.
Output

Print one integers: the number of distinct values.
Constraints

    1≤n≤2⋅1051≤n≤2⋅105
    1≤xi≤1091≤xi​≤10 */

#include <iostream>
#include <stdlib.h>
#include <set>
using namespace std;

int main(){
    set<int> valores; 
    int numeroInteiros;

    cin >> numeroInteiros;

    for (int i = 0; i < numeroInteiros; i++){
        long long valor = 0;
        cin >> valor;
        valores.insert(valor);
    }

    cout << valores.size() << endl;

    return 0;
}