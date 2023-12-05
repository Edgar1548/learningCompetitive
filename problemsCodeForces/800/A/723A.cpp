#include <bits/stdc++.h>
using namespace std;
void solve(){
    int x1;
    int x2;
    int x3;
    cin >> x1;
    cin >> x2;
    cin >> x3;
    if (x1 > max(x2, x3)) cout << x1 - min(x2, x3);
    else if (x1 < min(x2, x3)) cout << max(x2, x3) - x1;
    else cout << abs(x2-x3);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}