#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll po(ll x, int y)
{
    ll res = 1; 
    while (y > 0) {
        if (y & 1) res = res * x;
        y = y >> 1; 
        x = x * x;
    }
    return res;
}
void solve() { 
    ll N;
    cin >> N;
    int res = -1;
    for (ll i=1; i<16; i++){
        ll p = po(i, i);
        if (p == N){
            res = i;
        }
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();    
    return 0;
}