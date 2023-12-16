#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int toast = min((k*l)/nl, min(c*d, p/np));
    int maxToastByFriend = toast/n;
    cout << maxToastByFriend << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}