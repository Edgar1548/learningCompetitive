#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> parent;
vector<int> ranks;
struct edge{
    int u, v;
    int weigth;
    edge(int _u, int _v, int _w){
        u = _u;
        v = _v;
        weigth = _w;
    };
};
vector<edge> edges;

int Find(int x){
    while(parent[x] != x){
        x = parent[x];
    }
    return x;
}

void Union(int x, int y){
    if (ranks[x] < ranks[y]) parent[x] = y;
    else if (ranks[y] > ranks[x]) parent[y] = x;
    else {
        parent[y] = x;
        ranks[x] = ranks[x]+1;
    }
}
bool edge_cmpLexi(edge &a, edge &b){
    if (a.u == b.u) return a.v < b.v;
    return a.u < b.u;
}
bool edge_cmp(edge &a, edge &b){
    return a.weigth < b.weigth;
}
pair<ll, int> mst(int n, vector<edge> &resEdges){
    sort(edges.begin(), edges.end(), edge_cmp);
    ll res = 0, check = 0;
    for (int i=0; i<edges.size(); i++){
        int u = edges[i].u, v = edges[i].v;
        int ranksU = Find(u), ranksV = Find(v);
        if (ranksU != ranksV){
            Union(ranksU, ranksV);
            res += edges[i].weigth;
            resEdges.push_back(edges[i]);
            check += 1;
        }
    }
    return {res, check};
}

void solve(int n, int m){
    int a, b, w;
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    ranks.resize(n, 0);
    for (int i=0; i<m; i++){
        cin >> a >> b >> w;
        edge edg(a, b, w);
        if (edg.u > edg.v) swap(edg.u, edg.v);
        edges.push_back(edg);
    }
    vector<edge> resEdges;
    auto res = mst(n, resEdges);
    if (res.second < n-1) cout << "Impossible";
    else {
        sort(resEdges.begin(), resEdges.end(), edge_cmpLexi);
        cout << res.first << "\n";
        for (int i=0; i<resEdges.size(); i++){
            cout << resEdges[i].u << " " << resEdges[i].v <<  "\n"[i+1>=resEdges.size()];
        }
    }
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while(n != 0 || m != 0){
        solve(n, m);
        parent.clear();
        edges.clear();
        ranks.clear();
        cin >> n >> m;
    }
    return 0;
}