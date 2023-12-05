#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf = 1e9+1;
ll erastothenesModified(ll &n, ll &k){
    ll res = inf;
    ll size = sqrt(n) + 1;
    bool *isMarked = new bool[size];
    memset(isMarked, 0, size);
    ll i = 2;
    for (; i*i <= n; i++){
        if (n % i == 0) {
            ll q = n/i;
            if (i > k) break;
            res = min(res, q);
            if (q <= k) res = min(res, i);
        }
        if (!isMarked[i]){
            for(ll j = i; j<=size-1; j += i){
                isMarked[j] = true;
            }
        }
    }
    return res;
}

void solve(){
    ll n, k, res;
    cin >> n >> k;
    if (k >= n) res = 1;
    else if (k == 1) res = n;
    else {
        res = erastothenesModified(n, k);
        if (res == inf) res = n;
    }
    cout << res << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        solve();
    }
    return 0;
}