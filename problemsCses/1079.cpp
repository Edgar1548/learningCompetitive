#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int, int> mp;
ll modl = 1e9+7;
void compute(){
    mp[0] = 1;
    mp[1] = 1; 
    for (int i=2; i<=1e6; i++){
        mp[i] = ((mp[i-1] % modl) * (i%modl)) % modl;
    }
}
ll po(int b, ll e, ll modl){
    if (e == 0)
        return 1;
    else if (e == 1) return b%modl;
    ll x = (po(b, e >> 1, modl));
    x = (x*x)%modl;
    if (e % 2) x = (x * b) % (modl);
    return  x;
}

ll combinatory(int n, int k, ll modl){
    if (n <= k) return 1;
    ll res = 1;
    res = mp[n];
    res *= ((po(mp[k], modl-2, modl) % modl) * (po(mp[n-k], modl-2, modl) % modl)) % modl;
    res %= modl;
    return res;
}
void solve() {
    int a, b; 
    cin >> a >> b;
    ll tot =  combinatory(a, b, modl);
    cout << tot << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    compute();
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        solve();  
    }  
    return 0;
}