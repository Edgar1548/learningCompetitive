#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(ll k, ll n, ll w){
    ll res = k*(w*(w+1)/2) - n;
    if (res < 0) cout << 0;
    else cout << res;
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll k, n, w;
    cin >> k >> n >> w;
    solve(k, n, w);
    return 0;
}