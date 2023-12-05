#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll po(int b, int e, ll modl){
    if (e == 0)
        return 1;
    else if (e == 1) return b%modl;
    ll x = (po(b, e >> 1, modl));
    x = (x*x)%modl;
    if (e % 2) x = (x * b) % (modl);
    return x;

}

void solve(){
    int n; string str;
    cin >> n;
    cin >> str;
    ll res = 1;
    ll modl = 998244353;
    int p = 0;
    for (int i=1; i<n; i++){
        if (str[i] != str[i-1]) p = -1;
        p++;
        res += po(2, p, modl);
    }
    res %= modl;
    cout << res << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        solve();
    }
    return 0;
}      