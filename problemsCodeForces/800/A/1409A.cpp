#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll a, b;
    cin >> a >> b;
    ll r = abs(a-b);
    ll steps = r/10 + (r % 10 == 0 ? 0 : 1);
    cout << steps << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) solve();
    return 0;
}