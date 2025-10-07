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


    //inicializa uma segtree a partir de um array em tempo linear
    void build(vector<int> &a){
        build(a, 0, 0, size);
    }


    // set que sai atualizando os pais com os novos valores.
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
    // valores a serem adicionados e o seu indeactualNode
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


    return 0;
}