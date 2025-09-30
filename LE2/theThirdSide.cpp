/* The pink soldiers have given you a sequence aa consisting of nn positive integers.

You must repeatedly perform the following operation until there is only 11 element left.

    Choose two distinct indices ii and jj.
    Then, choose a positive integer value xx such that there exists a non-degenerate triangle∗∗ with side lengths aiai​, ajaj​, and xx.
    Finally, remove two elements aiai​ and ajaj​, and append xx to the end of aa. 

Please find the maximum possible value of the only last element in the sequence aa.

∗∗A triangle with side lengths aa, bb, cc is non-degenerate when a+b>ca+b>c, a+c>ba+c>b, b+c>ab+c>a.
Input

Each test contains multiple test cases. The first line contains the number of test cases tt (1≤t≤1041≤t≤104). The description of the test cases follows.

The first line of each test case contains a single integer nn (1≤n≤2⋅1051≤n≤2⋅105).

The second line of each test case contains nn integers a1,a2,…,ana1​,a2​,…,an​ (1≤ai≤10001≤ai​≤1000) — the elements of the sequence aa.

It is guaranteed that the sum of nn over all test cases does not exceed 2⋅1052⋅105.
Output

For each test case, output the maximum possible value of the only last element on a separate line. */

#include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;

int solve(priority_queue<int> &sequence){
    if (sequence.size() == 1)
        return sequence.top();

    while(sequence.size() > 1){
        int i = sequence.top();
        sequence.pop();

        int j = sequence.top();
        sequence.pop();

        int c = i + j - 1;
        sequence.push(c);
    }

    return sequence.top();
}

int main(){
    int testCases; 
    cin >> testCases;

    for (int i = 0; i < testCases; i++){
        int sequenceSize; 
        cin >> sequenceSize;

        priority_queue<int> sequence;

        for (int j = 0; j < sequenceSize; j++){
            int value = 0;
            cin >> value; 
        
            sequence.push(value);
        }

        cout << solve(sequence) << endl;
    }

    return 0;
}