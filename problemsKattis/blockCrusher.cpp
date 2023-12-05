#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> dist;
int supLimit = 1e9;
vector<vector<int>> arr;
unordered_map<int, pair<int, int>> positions;
unordered_map<int, int> parent;
unordered_map<int, bool> marked;
void dijkstra(int start, int nRow, int nCol, pair<int, int> &minCost){
    vector<pair<int, int>> valdMov = {{-1, 1}, {0, 1}, {1,1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}};
    dist[start] = arr[positions[start].first][positions[start].second];
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dist[start], start});
    while(!pq.empty()){
        int d = pq.top().first, u = pq.top().second;
        pair<int, int> posRC = positions[u];
        pq.pop();
        if (d > dist[u]) continue;
        for (int i=0; i<8; i++){
            int r = posRC.first + valdMov[i].second, c = posRC.second + valdMov[i].first;
            if (!(c >= 0 && c < nCol && r <= nRow && r >= 1)) continue;
            int v = r*nCol + c;   
            int w = arr[r][c];
            if (w + dist[u] < dist[v]){
                parent[v] = u;
                dist[v] = w + dist[u];
                pq.push({dist[v], v});
            }
            if (r == nRow) 
                minCost = (min(dist[v], minCost.first) == dist[v] ? make_pair(dist[v], v):minCost);
        }
    }
}

void solve(int r, int c){
    pair<int, int> minCostPos = {supLimit, -1};
    char number;
    arr.resize(r+1, vector<int>(c));
    for (int j=0; j<c; j++){
        positions[j] = {0, j};
        marked[j] = false;
        arr[0][j] = 0;
    }
    for (int i=1; i<=r; i++){
        for (int j=0; j<c; j++){
            positions[i*c+j] = {i, j};
            marked[i*c+j] = false;
            cin >> number;
            arr[i][j] = number - '0';
        }   
    }
    dist.resize((r+1)*c, supLimit);
    for (int i=0; i<c; i++){
        parent[i] = i;
        dijkstra(i, r, c, minCostPos);
    }
    int a = minCostPos.second;
    while(parent[a] != a){
        marked[a] = true;
        a = parent[a];
    }
    marked[a] = true;
    for (int i=1; i<=r; i++){
        for (int j=0; j<c; j++){
            if (marked[i*c+j]) cout << ' ';
            else cout << (char)(arr[i][j]+'0');
        }   
        cout << "\n";
    }
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r, c; cin >> r >> c;
    while(r != 0 || c != 0){
        solve(r, c);
        dist.clear();
        arr.clear();
        cin >> r >> c;
    }
    return 0;
}