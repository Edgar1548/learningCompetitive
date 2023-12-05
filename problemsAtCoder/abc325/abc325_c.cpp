#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<int, unordered_map<int, bool>> mapCoordenates;
int H, W, res = 0;
vector<vector<char>> arr;
bool findCoordenate(pair<int, int> coord){
    if (mapCoordenates.find(coord.first) == mapCoordenates.end()) return true;
    else if (mapCoordenates[coord.first].find(coord.second) == mapCoordenates[coord.first].end()) return true;
    return false;
}

void dfs(int i, int j){
    vector<pair<int, int>> movs = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
    pair<int, int> start = {i, j};
    bool check = true;
    stack<pair<int, int>> st;
    st.push(start);
    while(!st.empty()){
        start = st.top();
        st.pop();
        if (findCoordenate(start)){
            if (check) {
                res++;
                check = false;
            }
            mapCoordenates[start.first][start.second] = true;
            for (int k=0; k<movs.size(); k++){
                int x = start.second + movs[k].first;
                int y = start.first + movs[k].second;
                if (x < W && x >= 0 && y < H && y >= 0 && arr[y][x] == '#' && findCoordenate({y, x})){
                    st.push({y, x});
                }
            }
        }
    }
}
void solve(){
    cin >> H >> W;
    arr.resize(H, vector<char>(W));
    for (int i=0; i<H; i++){
        for (int j=0; j<W;j++){
            cin >> arr[i][j];
        }
    }
    for (int i=0; i<H; i++){
        for (int j=0; j<W;j++){
            if (arr[i][j] == '#') dfs(i, j);
        }
    }
    cout << res << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}