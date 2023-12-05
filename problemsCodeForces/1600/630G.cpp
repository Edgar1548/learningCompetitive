#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll combinatory(int n, int k){
    ll res = 1, div = 1, pos = 2;
    if (n >= k){
        for (int i=n; i>(n-k); i--){
            res *= i;
            if (res%pos == 0 && pos <= k) {
                res /= pos;
                pos++;
            }
        }
    } else {
        for (int i=2; i<=n; i++)res *= i;
    }
    for (int i=pos; i<=k; i++){
        div *= i;
    }
    res /= div;
    return res;
}
void solve() {
    int k; 
    ll variants = 0;
    cin >> k;
    variants += combinatory(5 + k - 1, 5);
    variants *= combinatory(3 + k - 1, 3);
    cout << variants << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();    
    return 0;
}