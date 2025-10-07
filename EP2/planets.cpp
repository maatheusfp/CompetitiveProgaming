/* One day, Vogons wanted to build a new hyperspace highway through a distant system with nn planets. The ii-th planet is on the orbit aiai​, there could be multiple planets on the same orbit. It's a pity that all the planets are on the way and need to be destructed.

Vogons have two machines to do that.

    The first machine in one operation can destroy any planet at cost of 11 Triganic Pu.
    The second machine in one operation can destroy all planets on a single orbit in this system at the cost of cc Triganic Pus. 

Vogons can use each machine as many times as they want.

Vogons are very greedy, so they want to destroy all planets with minimum amount of money spent. Can you help them to know the minimum cost of this project?
Input

The first line contains a single integer tt (1≤t≤1001≤t≤100) — the number of test cases. Then the test cases follow.

Each test case consists of two lines.

The first line contains two integers nn and cc (1≤n,c≤1001≤n,c≤100) — the number of planets and the cost of the second machine usage.

The second line contains nn integers a1,a2,…,ana1​,a2​,…,an​ (1≤ai≤1001≤ai​≤100), where aiai​ is the orbit of the ii-th planet.
Output

For each test case print a single integer — the minimum cost of destroying all planets. */

#include <iostream>
#include <stdlib.h>
#include <map>
using namespace std;

int main(){
    int testeCases;
    cin >> testeCases;

    for (int i = 0; i < testeCases; i++){
        int numInteiros, custoArma; 
        map<int, int> planetas;

        cin >> numInteiros >> custoArma;

        for (int j = 0; j < numInteiros; j++){
            int value;
            cin >> value;

            planetas[value]++;
        }

        int somaTotal = 0;

        for (auto it = planetas.begin(); it != planetas.end(); it++){
            if (it->second < custoArma){
                somaTotal += it->second;
            } else {
                somaTotal += custoArma;
            }
        }

        cout << somaTotal << endl;
    }

    return 0;
}