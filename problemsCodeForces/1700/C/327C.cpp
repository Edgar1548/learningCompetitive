#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modl = 1e9+7;
ll po(ll b, ll e){
    if (e == 0)
        return 1;
    else if (e == 1) return b%modl;
    ll x = (po(b, e >> 1));
    x = (x*x)%modl;
    if (e % 2) x = (x * b) % (modl);
    return  x;
}

void solve() {
    string str;
    ll k;
    ll tot = 0;
    cin >> str >> k;
    ll top = (po(2, k*str.size()) - 1) % modl;
    ll bot = (po((po(2, str.size()) -1) % modl, modl-2)) % modl;
    for (int i=0; i<str.size(); i++){
        if (str[i] == '5' || str[i] == '0'){
            tot += (po(2, i) % modl);
            tot %= modl;
        }
    }   
    tot *= (top * bot) % modl;
    cout << tot % modl << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve(); 
    return 0;
}