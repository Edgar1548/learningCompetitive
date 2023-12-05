    #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int, bool> visited;
queue<pair<int, int>> qu;

void solve(int n, int m){
    ll res;
    queue<pair<ll, int>> qu;
    qu.push({n, 0});
    ll minActual = 1e7;
    ll tempMin;
    pair<ll, int> actual;
    int steps = 0;
    while(!qu.empty()){
        actual = qu.front();
        qu.pop();
        if (actual.first >= m){ 
            tempMin = actual.first - m + actual.second;
            if (minActual > tempMin) minActual = tempMin;
        }
        else {
            if (!visited[2*actual.first]) {
                visited[2*actual.first] = true;
                qu.push({2*actual.first, actual.second+1});
            }
            if (!visited[actual.first-1] && actual.first >= 1){
                visited[actual.first-1] = true;
                qu.push({actual.first-1, actual.second+1});
            }
        }
    };
    cout << minActual << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    solve(n, m);
    return 0;
}