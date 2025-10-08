#include <bits/stdc++.h>
using namespace std;

struct Segtree{
    long long size;
/*     vector<long long> sums;
 */    vector<long long> mins;

    void init(long long n){
        size = 1; 
        while (size < n ) size *= 2;
        mins.assign(2*size, LLONG_MAX);
    }

    void build(vector<long long> &a, long long actualNode, long long leftBorder, long long rightBorder){
        if (rightBorder - leftBorder == 1){
            if (leftBorder < (long long)a.size()){
/*                 sums[actualNode] = a[leftBorder];
 */                mins[actualNode] = a[leftBorder];
            }
            return;
        }

        long long m = (leftBorder + rightBorder) / 2;
        build(a, 2 * actualNode + 1, leftBorder, m);
        build(a, 2 * actualNode + 2, m, rightBorder);
/*         sums[actualNode] = sums[2 * actualNode + 1] + sums[2 * actualNode + 2];
 */        mins[actualNode] = min(mins[2 * actualNode + 1], mins[2 * actualNode + 2]);
    }

    void build(vector<long long> &a){
        build(a, 0, 0, size);
    }

    void set(long long indeactualNode, long long valueToBeAdded, long long actualNode, long long leftBorder, long long rightBorder){
        if (rightBorder - leftBorder == 1){
/*             sums[actualNode] = valueToBeAdded;
 */            mins[actualNode] = valueToBeAdded; 
            return;
        }

        long long meio = (leftBorder + rightBorder) / 2;
        if (indeactualNode < meio){
            set(indeactualNode, valueToBeAdded, 2*actualNode + 1, leftBorder, meio);
        } 
        else {
            set(indeactualNode, valueToBeAdded, 2*actualNode+2, meio, rightBorder);
        }

/*         sums[actualNode] = sums[2*actualNode + 1] + sums[2*actualNode + 2];
 */        mins[actualNode] = min(mins[2*actualNode + 1], mins[2*actualNode + 2]);
    }

    void set(long long indeactualNode, long long value){
        set(indeactualNode, value, 0, 0, size);
    }


/*     long long sum(long long l, long long r, long long actualNode, long long leftBorder, long long rightBorder){
        if (leftBorder >= r || l >= rightBorder) return 0;
        if (leftBorder >= l && rightBorder <= r) return sums[actualNode];

        long long m = (leftBorder + rightBorder) / 2;
        long long s1 = sum(l, r, 2*actualNode + 1, leftBorder, m);
        long long s2 = sum(l, r, 2*actualNode + 2, m, rightBorder);
        return s1 + s2;
    }

    long long sum(long long l, long long r){
        return sum(l, r, 0, 0, size);
    } */

    long long minQuery(long long l, long long r, long long actualNode, long long leftBorder, long long rightBorder){
        if (leftBorder >= r || l >= rightBorder) return LLONG_MAX;
        if (leftBorder >= l && rightBorder <= r) return mins[actualNode];

        long long m = (leftBorder + rightBorder) / 2;
        long long min1 = minQuery(l, r, 2*actualNode + 1, leftBorder, m);
        long long min2 = minQuery(l, r, 2*actualNode + 2, m, rightBorder);
        return min(min1, min2);
    }

    long long minQuery(long long l, long long r){
        return minQuery(l, r, 0, 0, size);
    }

};


int main(){
    long long n, q;
    cin >> n >> q;

    vector<long long> valuesArray;

    for (long long i = 0; i < n; i++){ 
        long long value; 
        cin >> value;
        valuesArray.push_back(value);
    }

    Segtree st;
    st.init(n);
    st.build(valuesArray);

    while (q--){
        long long op, kOrA, uOrB;
        cin >> op >> kOrA >> uOrB;

        if (op == 1)
            st.set(kOrA - 1, uOrB);
        
        else 
            cout << st.minQuery(kOrA - 1, uOrB) << endl;
    }

    return 0;
}