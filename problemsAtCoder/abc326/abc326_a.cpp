#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int x, y;
    cin >> x >> y;
    if (y <= x + 2 && y >= x-3) cout << "Yes";
    else cout << "No";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();    
    return 0;
}