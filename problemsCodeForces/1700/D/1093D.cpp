#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll modl = 998244353;
vector<vector<int>> vc;
unordered_map<int, bool> visiteds;  

void solve(ll n, ll m){
    vc.resize(n+1);
    for (int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        vc[u].push_back(v);
        vc[v].push_back(u);
        visiteds[u] = false;
        visiteds[v] = false;
    }
    ll sumTotal = 1;
    unordered_map<int, bool> connected = visiteds;
    unordered_map<int, pair<int, int>> statusMap;
    for (int i=1; i<=n; i++){   
        if (connected[i] == false){
            ll sumPair = 1;
            ll sumImpair = 1;
            stack<pair<int, pair<int, int>>> st;
            st.push({i, {1, 2}});
            pair<int, pair<int, int>> actual;
            while(!st.empty()){
                actual = st.top();
                st.pop();
                if (connected[actual.first] == false){
                    connected[actual.first] = true;
                    if (actual.second.first == 1) sumImpair = (2*sumImpair)%modl;
                    if (actual.second.second == 1) sumPair = (2*sumPair)%modl;
                    for (int j=0; j<vc[actual.first].size(); j++){
                        if (connected[vc[actual.first][j]] == false){
                            //cout << "stMemer: " << vc[actual.first][i] << "from: " << actual.first << endl;
                            if (statusMap.find(vc[actual.first][j]) != statusMap.end()){
                                if (statusMap[vc[actual.first][j]].first == statusMap[actual.first].first || statusMap[vc[actual.first][j]].second == statusMap[actual.first].second){
                                    sumPair = 0;
                                    sumImpair = 0;
                                    break;
                                } else continue;
                            } 
                            if (actual.second.first == 1) {
                                st.push({vc[actual.first][j], {2, 1}});
                                statusMap[vc[actual.first][j]] = {2, 1};
                            } else {
                                st.push({vc[actual.first][j], {1, 2}});
                                statusMap[vc[actual.first][j]] = {1, 2};
                            }
                        }
                    }
                    if (sumPair == 0 || sumImpair == 0) break;
                }
            }   
            if (sumImpair == 0 || sumPair == 0) {
                sumTotal = 0;
                break;
            }
            else {
                sumTotal = (sumTotal*(sumImpair+sumPair)%modl)%modl;
            }
        }
    }
    cout << sumTotal << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, t;
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> n >> m;
        solve(n, m);
        visiteds.clear();
        vc.clear();
    }
    return 0;
}
