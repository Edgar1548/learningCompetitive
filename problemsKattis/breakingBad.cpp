#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> adj;
unordered_map<string, int> itemMap;  
unordered_map<int, string> itemPos;
vector<int> itemList;
vector<vector<int>> oneTwo(3);
unordered_map<int, bool> visited;

bool dfs(int i){
    stack<int> st;
    st.push(i);
    while(!st.empty()){
        int actual = st.top();
        st.pop();
        if (visited.find(actual) == visited.end()){
            visited[actual] = true;
            if (itemList[actual] == 0){
                oneTwo[2].push_back(actual);
                itemList[actual] = 2;
            }
            for (int j=0; j<adj[actual].size(); j++){
                st.push(adj[actual][j]);
                if (itemList[adj[actual][j]] == itemList[actual]) {
                    return false;
                } else if (itemList[adj[actual][j]] == 0){
                    oneTwo[itemList[actual] == 1? 2: 1].push_back(adj[actual][j]);
                    itemList[adj[actual][j]] = itemList[actual] == 1? 2: 1;
                }
            }
        }
    }
    return true;
}

void solve(){
    int n, m;
    string name, u, v;
    bool possible;
    cin >> n;
    adj.resize(n);
    for (int i=0; i<n; i++){
        cin >> name;
        itemMap[name] = i;
        itemPos[i] = name;
        itemList.push_back(0);
    }
    cin >> m;
    for (int i=0; i<m; i++){
        cin >> u >> v;  
        adj[itemMap[u]].push_back(itemMap[v]);
        adj[itemMap[v]].push_back(itemMap[u]);
    }
    oneTwo[1].push_back(0);
    itemList[0] = 1;
    for (int i=0; i<n; i++){
        possible = dfs(i);
        if (!possible) break;
    }
    if (!possible || n <= 1) cout << "impossible";
    else {
        for (auto it: oneTwo[1]){
            cout << itemPos[it] << " ";
        }
        cout <<"\n";
        for (auto it: oneTwo[2]){
            cout << itemPos[it] << " ";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}