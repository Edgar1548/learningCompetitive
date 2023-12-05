#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modl = 1000000007;
ll po(int b, ll e, ll modl){
    if (e == 0)
        return 1;
    else if (e == 1) return b%modl;
    ll x = (po(b, e >> 1, modl));
    x = (x*x)%modl;
    if (e % 2) x = (x * b) % (modl);
    return  x;
}

void solve() {
    ll d; 
    cin >> d;
    ll semiRes = po(9, d-1, modl);
    ll total = (semiRes%modl * 8)%modl;
    cout << total << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        solve();  
    }  
    return 0;
}