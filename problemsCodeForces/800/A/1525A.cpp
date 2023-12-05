#include <bits/stdc++.h>
using namespace std;
void solve(){
    int e;
    cin >> e;
    int w = 100-e;
    int res = 0;
    if (e == 0 || w == 0)  res += 1;
    else {
        int gcd = __gcd(e,w);
        res += w/gcd + e/gcd;
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
