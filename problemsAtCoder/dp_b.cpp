#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> vc;
unordered_map<int, ll> dpMap;
int k;
int dp(int p, ll val, int n){   
    if (p == n-1) return val;
    if (dpMap[p] != -1) return dpMap[p] + val;
    ll v = -1;
    for (int i=1; i<=k; i++){
        if (p + i >= n) break;
        ll vtemp = dp(p+i, val + abs(vc[p] - vc[p+i]), n);
        v = v == -1? vtemp : vtemp < v ? vtemp : v;
    }   
    dpMap[p] = v - val;
    return v;
}
void solve(int n){

    ll val = dp(0, 0, n);
    cout << val;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n; cin >> k;
    for (int i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        vc.push_back(temp);
        dpMap[i] = -1;
    }
    solve(n);
    return 0;
}