#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> vc;
vector<vector<ll>> dpMt;
ll costTo(int pos, int to){
    return abs(vc[pos] - to);
}
ll dp(ll cost, int pos, bool needNeg, int n){
    if (pos == n){
        if (needNeg) return cost + costTo(pos, -1);
        else return cost + costTo(pos, 1);
    }
    if (dpMt[pos][needNeg] != -1) return cost + dpMt[pos][needNeg];
    ll c, nc;
    if (needNeg){   
        c = dp(cost + costTo(pos, 1), pos+1, true, n);
        nc = dp(cost + costTo(pos, -1), pos+1, false, n);
    } else {
        c = dp(cost + costTo(pos, 1), pos+1, false, n);
        nc = dp(cost + costTo(pos, -1), pos+1, true, n);
    }
    dpMt[pos][needNeg] = min(c, nc) - cost ;
    return dpMt[pos][needNeg] + cost;
}

void solve(ll n){
    ll res;
    res = dp(0, 0, false, n-1);
    int pos = 0;
    cout << res << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    ll temp;
    cin >> n;
    dpMt.resize(n, vector<ll>(2, -1));
    for (int i=0; i<n; i++){
        cin >> temp;
        vc.push_back(temp);
    }
    solve(n);
    return 0;
}
