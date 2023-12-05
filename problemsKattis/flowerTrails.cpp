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
vector<int> parent;
vector<ll> cost;
vector<ll> ranks;
ll inf = 2e11 - 1;

int Find(int u, int v){
    while (ranks[v] > ranks[u]){
        v = parent[v];
    }
    while (ranks[u] > ranks[v]){
        u = parent[u];
    }
    while (v != u){
        v = parent[v];
        u = parent[u];
    }
    return u;
}
void dijkstra(int start, int end){
    dist[start] = 0;
    cost[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dist[start], start});
    while(!pq.empty()){
        int u = pq.top().second; ll d = pq.top().first;
        pq.pop();
        if (d > dist[u]) 
            continue; 
        for (int i=0; i<adj[u].size(); i++){
            ll v = adj[u][i].v,
                w = adj[u][i].weigth;
            if (w + dist[u] < dist[v]){
                ranks[v] = ranks[u]+1;
                parent[v] = u;
                cost[v] = w + cost[u];
                dist[v] = w + dist[u];
                pq.push({dist[v], v});
            }
            else if (w + dist[u] == dist[v]){
                int tempU = u;
                tempU = Find(u, v);
                cost[v] += cost[u] + w - cost[tempU];
                parent[v] = u; 
            }
        }
    }
}

void solve(){
    int n, m, a, b, w;
    cin >> n >> m;
    adj.resize(n);
    parent.resize(n);
    cost.resize(n, 0);
    ranks.resize(n, 0);
    dist.resize(n, inf);
    for (int i=0; i<m; i++){
        cin >> a >> b >> w;
        if (a != b){
            adj[a].push_back(edge(a, b, w));
            adj[b].push_back(edge(b, a, w));
        }
    }
    dijkstra(0, n-1);
    ll totalCost = 2*cost[n-1];
    cout << totalCost;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}