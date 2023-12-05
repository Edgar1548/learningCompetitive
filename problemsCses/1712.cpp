#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
unordered_map<ll, unordered_map<ll, ll>> umap;
ll modg = 1e9 + 7;

ll po(ll b, ll e, ll modl){
    if (e == 0)
        return 1;
    else if (e == 1) return b%modl;
    //if ((umap.find(b) != umap.end()) && (umap[b].find(e) != umap[b].end())) return umap[b][e];
    ll x = (po(b, e >> 1, modl));
    x = (x*x)%modl;
    if (e % 2)
        x = (x * b) % (modl);
    return  x;
    //return x;
}

void solve(){
    ll a, b, c;
    cin >> a >> b >> c;

    ll exp = po(b, c, modg-1);
    cout << po(a, exp, modg)<< "\n";
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