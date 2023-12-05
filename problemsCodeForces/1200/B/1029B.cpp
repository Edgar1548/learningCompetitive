#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> vc;
unordered_map<int, int> dpMap;
ll dp(ll cost, ll pos, int lastChoosen, ll n){
    if (pos == n) return cost;
    if (dpMap[pos] != -1) 
        if (cost != 0) return dpMap[pos] + cost; 
        else return dp(cost, pos+1, lastChoosen, n);
    ll c, nC;
    if (cost == 0 || vc[pos] <= vc[lastChoosen]*2){
        c = dp(cost + 1, pos + 1, pos, n);
        nC= dp(cost, pos + 1, lastChoosen, n);
        dpMap[pos] = max(c, nC) - cost;
        return dpMap[pos] + cost;
    } else return cost;
}

void solve(int n){
    vc.resize(n);
    for (int i=0; i<n; i++){
        cin >> vc[i];
        dpMap[i] = -1;
    }
    ll res;
    res = dp(0, 0, 0, n);
    /* for(auto it: dpMap){
        cout << it.first << " " << it.second << endl; 
    } */

    cout << res << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n);
    return 0;
}      
