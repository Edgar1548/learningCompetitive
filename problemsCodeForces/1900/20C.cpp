#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge{
    int u, v;
    int weigth;
    edge(int _u, int _v, int _w){
        u = _u;
        v = _v;
        weigth = _w;
    };
};
vector<vector<edge>> adj;
vector<ll> dist;
unordered_map<int, int> parent;
ll supLimit = 2e11+1;

void dijkstra(int start, int end){
    dist[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dist[start], start});
    while(!pq.empty()){
        int u = pq.top().second; ll d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        if (u == end) break;
        for (int i=0; i<adj[u].size(); i++){
            ll v = adj[u][i].v,
                w = adj[u][i].weigth;
            if (w + dist[u] < dist[v]){
                parent[v] = u;
                dist[v] = w + dist[u];
                pq.push({dist[v], v});
            }
        }
    }
}

void solve(){
    int n, m, a, b, w;
    cin >> n >> m;
    adj.resize(n+1);
    dist.resize(n+1, supLimit);
    parent[1] = 1;
    for (int i=0; i<m; i++){
        cin >> a >> b >> w;
        adj[a].push_back(edge(a, b, w));
        adj[b].push_back(edge(b, a, w));
    }
    dijkstra(1, n);
    if (dist[n] == supLimit){
        cout << -1;
    } else{
        vector<int> res;
        res.push_back(n);
        int p = parent[n];
        while(p != 1){
            res.push_back(p);
            p = parent[p];
        }
        res.push_back(1);
        for (int i=res.size()-1; i>=0; i--){
            cout << res[i] << " ";
        }
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}