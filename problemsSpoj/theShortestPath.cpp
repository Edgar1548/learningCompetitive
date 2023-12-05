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
unordered_map<string, int> cityMap;  
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
                dist[v] = w + dist[u];
                pq.push({dist[v], v});
            }
        }
    }
}

void solve(){
    int n, m, v, w, r;
    string name, from, to;
    cin >> n;
    adj.resize(n+1);
    for (int i=1; i<=n; i++){
        cin >> name >> m;
        cityMap[name] = i;
        for (int j=0; j<m; j++){
            cin >> v >> w;
            adj[i].push_back(edge(i, v, w));
            adj[v].push_back(edge(v, i, w));
        }
    }
    cin >> r;
    for (int i=0; i<r; i++){
        dist.clear();
        dist.resize(n+1, supLimit);
        cin >> from >> to;
        dijkstra(cityMap[from], cityMap[to]);
        cout <<dist[cityMap[to]] << "\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    for (int i=0; i<t; i++){
        solve();
        cityMap.clear();
        adj.clear();    
    }
    return 0;
}