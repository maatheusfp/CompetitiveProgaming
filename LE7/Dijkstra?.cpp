#include <bits/stdc++.h>
using namespace std;

#define INF 1e18
#define ll long long

typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;

vector<vii> AdjList;

void printPath(ll u, vi& p, ll s) {
    if (u == s) {
        cout << s;
        return;
    }
    printPath(p[u], p, s);
    cout << " " << u;
}


void dijkstra_single_pair(ll s, ll t) {
    ll V = AdjList.size();
    vi dist(V, INF);
    vi p(V, -1);
    
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0, s));
    
    while (!pq.empty()) {
        ii front = pq.top();
        pq.pop();
        
        ll d = front.first;
        ll u = front.second;
        
        if (d > dist[u]) continue;
        
        if (u == t) break;
        
        for (ll j = 0; j < (ll)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                p[v.first] = u;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }
    
    if (dist[t] == INF) {
        cout << -1 << endl;
    } else {
        printPath(t, p, s);
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    
    AdjList.assign(n + 1, vii());
    
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        AdjList[u].push_back(ii(v, w));
        AdjList[v].push_back(ii(u, w));
    }
    
    dijkstra_single_pair(1, n);
    
    return 0;
}