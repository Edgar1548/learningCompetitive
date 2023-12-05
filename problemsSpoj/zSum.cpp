#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> umap;
ll modl = 10000007;

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

void solve(ll n, ll k){
    ll n_k = po(n, k);
    ll n_1_k = po(n-1, k);
    ll n_n = po(n, n);
    ll n_1_n = po(n-1, n-1);
    
    ll n_1 = (2*n_1_k)%modl;
    n_1 = (n_k + n_1);
    ll n_2 = (2*n_1_n)%modl;
    n_2 = (n_n + n_2);  

    ll res = (n_1 + n_2)%modl;
    cout << res << "\n"; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, k; 
    cin >> n >> k;
    while(n != 0 && k !=0){
        solve(n, k);
        cin >> n >> k;
    }   
    return 0;
}     