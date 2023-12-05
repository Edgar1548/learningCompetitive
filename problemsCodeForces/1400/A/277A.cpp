#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int, bool> visited; 
void dfs(int v, vector<set<int>> adj){
    visited[v] = true;
    for (auto it= adj[v].begin(); it != adj[v].end(); it++){
        if (!visited[*it]) dfs(*it, adj);
    }
}

void solve(int n, int m){
    vector<int> lang[m+1];
    vector<set<int>> adj(n+1);
    int k; int totalCantity; int cantity;  int element;
    for (int i=1; i<=n; i++){
        visited[i] = false;
        cin >> cantity;
        totalCantity += cantity;
        for (int j=0; j<cantity; j++){
            cin >> element;
            lang[element].push_back(i);
        }
    }
    for (int i=1; i<=m; i++){
        if (!lang[i].empty()) {
            for (int j=0; j<lang[i].size(); j++){
                for (int p=j+1; p<lang[i].size(); p++){
                    adj[lang[i][j]].insert(lang[i][p]);
                    adj[lang[i][p]].insert(lang[i][j]);
                }
            }
        }
    }
    int counter = 0;
    for (int i=1; i<=n; i++){
        if (!visited[i]) {
            counter++;
            dfs(i, adj);
        }
    }
    if (totalCantity == 0) counter = n+1;
    cout << counter - 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    solve(n, m);
    return 0;
}