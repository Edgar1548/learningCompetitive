#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int, bool> visited; 


pair<int, int> bfsOneIter(int n, int m, vector<vector<int>> adj){
    int y, x;
    if (adj[1].size() == 1) {
        y = adj[adj[1][0]].size();
        x = m/y;
    } 
    else {
        int maxChildrenPos = 0;
        bool isY = false;
        for (int i=0; i<adj[1].size(); i++){
            if (adj[adj[1][i]].size() == 1) isY = true;
            maxChildrenPos = adj[adj[1][maxChildrenPos]].size() < adj[adj[1][i]].size() ? i : maxChildrenPos;
        }
        if (isY){
            y = adj[1].size();
            x = adj[adj[1][maxChildrenPos]].size();
        } else {
            x = adj[1].size();
            y = adj[adj[1][0]].size();
        }
    }
    return {x, y-1};
}

void solve(int n, int m){
    vector<vector<int>> adj(n+1);
    for (int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        visited[i] = false;
    }
    pair<int, int> pair_x_y = {0, 0};
    pair_x_y = bfsOneIter(n, m, adj);
    
    cout << pair_x_y.first << " " << pair_x_y.second << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> n >> m;
        solve(n, m);
    }
    return 0;
}