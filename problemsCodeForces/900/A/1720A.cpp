#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ad = a*d, bc = b*c;
    int res = 0;
    if (ad != bc){
        res++;
        if (ad != 0 && bc != 0 && ad % bc != 0 && bc % ad != 0) res++;
    } 
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