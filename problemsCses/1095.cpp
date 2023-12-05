#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
unordered_map<ll, unordered_map<ll, ll>> umap;
ll modl = 1e9 + 7;

ll po(ll b, ll e){
    if (e == 0)
        return 1;
    else if (e == 1) return b%modl;
    ll x = (po(b, e >> 1));
    x = (x*x)%modl;
    if (e % 2)
        x = (x * b) % (modl);
    return x;
}

void solve(){
    ll a, b;
    cin >> a >> b;
    a = a % modl;
    cout << po(a, b) << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}