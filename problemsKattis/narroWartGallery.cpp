#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
vector<vector<int>> vc;
vector<vector<vector<ll>>> dpMap;
unordered_map<int, int> totalU;
ll dp(ll val, int row, ll k, ll total, ll impossible, int n){
    if (k == 0) return val + total - totalU[row-1];
    ll a=0, b=0, c=0;
    if (dpMap[row][k][impossible] != -1) return dpMap[row][k][impossible] + val;
    if (impossible != 1) a = dp(val + vc[row][1], row+1, k-1, total, 2, n);
    if (impossible != 2) b = dp(val + vc[row][0], row+1, k-1, total, 1, n);
    if (k != n - row + 1) c = dp(val + vc[row][0] + vc[row][1], row+1, k, total, 0, n);
    dpMap[row][k][impossible] = max(a, max(b, c)) - val;
    return dpMap[row][k][impossible] + val;

}

void solve(int n, int k){
    ll total = 0, l, r;
    vc.resize(n+1, vector<int>(2));
    dpMap.resize(n+1, vector<vector<ll>>(k+1, vector<ll>(3, -1)));
    for (int i=1; i<=n; i++){
        cin >> l >> r;
        vc[i][0] = l;
        vc[i][1] = r;
        total += vc[i][0] + vc[i][1];
        totalU[i] = total;
    }
    ll res;
    res = dp(0, 1, k, total, 0, n);
    cout << res << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    while(n != 0 || k != 0){
        solve(n, k);
        cin >> n >> k;
    }
    return 0;
}      
