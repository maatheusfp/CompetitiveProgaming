/* You are given an array of nn integers, and your task is to find two values (at distinct positions) whose sum is xx.
Input

The first input line has two integers nn and xx: the array size and the target sum.

The second line has nn integers a1,a2,…,ana1​,a2​,…,an​: the array values.
Output

Print two integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.
Constraints

    1≤n≤2⋅1051≤n≤2⋅105
    1≤x,ai≤1091≤x,ai​≤109
 */

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

int main(){
    int n, x;

    cin >> n >> x;
    vector<int> array;

    for (int k = 0; k < n; k++){
        int value; 
        cin >> value;
        
        array.push_back(value);
    }

    bool achou = false;
    int i = 0;

    while (!achou && i < n){
        int j = 1;
        while (!achou && j < n){ 
            if(i == j){
                j++;
                continue;
            }

            if (array[i] + array[j] == x){
                cout << i + 1 << " " << j + 1 << endl;
                achou = true;
            }
            j++;
        }
        i++ ;
    }

    if (!achou)
        cout << "IMPOSSIBLE" << endl;

    return 0;
}