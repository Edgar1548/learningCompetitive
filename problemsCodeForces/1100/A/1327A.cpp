#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n, k;
    cin >> n >> k;
    bool possible = true;
    if (k > n/2 && n > 1) possible = false;
    else if (n % 2 == 0 && k % 2 != 0) possible = false;
    else if (n % 2 != 0 && k % 2 == 0) possible = false;
    else {
        ll maxPossible = (n % 2 == 0 ? pow(n/2, 2) - pow(n/2-k, 2) : pow(n/2+1, 2) - pow(n/2+1-k, 2));
        ll minPossible = pow(k, 2);
        if (n > maxPossible || n < minPossible) possible = false;
    }
    if (possible) cout << "YES";
    else cout << "NO";
    cout << "\n";
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