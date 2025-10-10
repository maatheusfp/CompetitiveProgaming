#include <bits/stdc++.h>
using namespace std;

struct fenwickTree {
    vector<int> tree;
    int n;
    
    void init(int size) {
        n = size;
        tree.assign(n + 1, 0);
    }
    
    void update(int idx, int val) {
        for(int i = idx; i <= n; i += i & (-i)) {
            tree[i] += val;
        }
    }
    
    int query(int idx) {
        int sum = 0;
        for(int i = idx; i > 0; i -= i & (-i)) {
            sum += tree[i];
        }
        return sum;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        vector<pair<int, int>> people(n);
        vector<int> endpoints;

        for(int i = 0; i < n; i++){
            cin >> people[i].first >> people[i].second;
            endpoints.push_back(people[i].second);
        }
        
        sort(endpoints.begin(), endpoints.end());
        endpoints.erase(unique(endpoints.begin(), endpoints.end()), endpoints.end());
        
        sort(people.begin(), people.end());
        
        long long greetings = 0;
        fenwickTree bit;
        bit.init(endpoints.size());
        
        for(int i = 0; i < n; i++){
            int pos = lower_bound(endpoints.begin(), endpoints.end(), people[i].second) - endpoints.begin() + 1;
            
            greetings += bit.query(endpoints.size()) - bit.query(pos);
            
            bit.update(pos, 1);
        }
        
        cout << greetings << endl;
    }
    
    return 0;
}