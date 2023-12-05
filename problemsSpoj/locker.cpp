#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> umap;
ll modl = 1e9 + 7;

ll po(int b, ll e){
    if (e == 0)
        return 1;
    if (umap.find(e) != umap.end())
        return umap[e];
    ll x = (po(b, e / 2) * po(b, e / 2)) % (modl);
    if (e % 2)
        x = (x * b) % (modl);
    return umap[e] = x;
}
ll locker(ll r){
    if (r <= 4)
        return r;
    else if (r % 3 == 1)
        return (po(3, (r - 4) / 3) * 4) % (modl);
    else if (r % 3 == 2)
        return (po(3, (r - 2) / 3) * 2) % (modl);
    else
        return (po(3, r / 3)) % (modl);
}
void solve(){
    ll n;
    cin >> n;
    auto max = locker(n);
    cout << max << "\n";
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