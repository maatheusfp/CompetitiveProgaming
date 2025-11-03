/* After the lessons n groups of schoolchildren went outside and decided to visit Polycarpus to celebrate his birthday. We know that the i-th group consists of si friends (1 ≤ si ≤ 4), and they want to go to Polycarpus together. They decided to get there by taxi. Each car can carry at most four passengers. What minimum number of cars will the children need if all members of each group should ride in the same taxi (but one taxi can take more than one group)?
Input

The first line contains integer n (1 ≤ n ≤ 105) — the number of groups of schoolchildren. The second line contains a sequence of integers s1, s2, ..., sn (1 ≤ si ≤ 4). The integers are separated by a space, si is the number of children in the i-th group.
Output

Print the single number — the minimum number of taxis necessary to drive all children to Polycarpus. */

#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define ll long long 

int main()
{
    int n; 
    cin >> n;
    
    int grupo[5] = {0};
    
    for (int i = 0; i < n; i++){
        int value; 
        cin >> value;
        grupo[value]++;
    }
    
    int taxis = 0;

    // 4
    taxis += grupo[4];

    // 3 - 1
    int pairs_3_1 = min(grupo[3], grupo[1]);
    taxis += pairs_3_1;
    grupo[3] -= pairs_3_1;
    grupo[1] -= pairs_3_1;

    // 3 solto
    taxis += grupo[3];

    // 2 - 2
    taxis += grupo[2] / 2;
    grupo[2] %= 2;

    // 2 - 1 - 1 
    if (grupo[2] > 0){
        taxis++;
        grupo[1] -=min(grupo[1], 2);
    }

    // 1-1-1-1
    taxis += (grupo[1] + 3) / 4;

    cout << taxis << endl;
    
    return 0;
}