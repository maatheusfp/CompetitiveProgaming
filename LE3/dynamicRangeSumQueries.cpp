/* Given an array of nn integers, your task is to process qq queries of the following types:

    update the value at position kk to uu
    what is the sum of values in range [a,b][a,b]?

Input

The first input line has two integers nn and qq: the number of values and queries.

The second line has nn integers x1,x2,…,xnx1​,x2​,…,xn​: the array values.

Finally, there are qq lines describing the queries. Each line has three integers: either "11 kk uu" or "22 aa bb".
Output

Print the result of each query of type 2.
Constraints

    1≤n,q≤2⋅1051≤n,q≤2⋅105
    1≤xi,u≤1091≤xi​,u≤109
    1≤k≤n1≤k≤n
    1≤a≤b≤n1≤a≤b≤n */



#include <bits/stdc++.h>
using namespace std; 
    
struct Segtree{
    int size;
    vector<long long> sums;

    void init(int n){
        size = 1; 
        while (size < n ) size *= 2;
        sums.assign(2*size, 0LL); 
    }

    void build(vector<int> &a, int actualNode, int leftBorder, int rightBorder){
        if (rightBorder - leftBorder == 1){
            if (leftBorder < (int)a.size()){
                sums[actualNode] = a[leftBorder];
            }
            return;
        }

        int m = (leftBorder + rightBorder) / 2;
        build(a, 2 * actualNode + 1, leftBorder, m);
        build(a, 2 * actualNode + 2, m, rightBorder);
        sums[actualNode] = sums[2 * actualNode + 1] + sums[2 * actualNode + 2];
    }

    void build(vector<int> &a){
        build(a, 0, 0, size);
    }

    void set(int indeactualNode, int valueToBeAdded, int actualNode, int leftBorder, int rightBorder){
        if (rightBorder - leftBorder == 1){
            sums[actualNode] = valueToBeAdded;
            return;
        }

        int meio = (leftBorder + rightBorder) / 2;
        if (indeactualNode < meio){
            set(indeactualNode, valueToBeAdded, 2*actualNode + 1, leftBorder, meio);
        } 
        else {
            set(indeactualNode, valueToBeAdded, 2*actualNode+2, meio, rightBorder);
        }

        sums[actualNode] = sums[2*actualNode + 1] + sums[2*actualNode + 2];

    }

    void set(int indeactualNode, int value){
        set(indeactualNode, value, 0, 0, size);
    }


    long long sum(int l, int r, int actualNode, int leftBorder, int rightBorder){
        if (leftBorder >= r || l >= rightBorder) return 0;
        if (leftBorder >= l && rightBorder <= r) return sums[actualNode];

        int m = (leftBorder + rightBorder) / 2;
        long long s1 = sum(l, r, 2*actualNode + 1, leftBorder, m);
        long long s2 = sum(l, r, 2*actualNode + 2, m, rightBorder);
        return s1 + s2;
    }

    long long sum(int l, int r){
        return sum(l, r, 0, 0, size);
    }
};

int main(){

    int n, q;
    cin >> n >> q;

    vector<int> arrayValue;
    for (int i =0; i < n; i++){
        int value; 
        cin >> value;

        arrayValue.push_back(value);
    }

    Segtree st;
    st.init(n);
    st.build(arrayValue);

    while(q--){
        int op, kOrA;
        long long uOrB;

        cin >> op >> kOrA >> uOrB;

        if (op == 1)
            st.set(kOrA - 1, uOrB);
        else 
            cout << st.sum(kOrA - 1, uOrB) << endl;

    }

    return 0;
}