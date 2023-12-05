#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    ll n, res;
    cin >> n;
    res = 6*((n)*(n+1))/2 + 1;
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();    
    return 0;
}