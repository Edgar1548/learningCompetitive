#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll combinatory(int n, int k){
    ll res = 1;
    ll div = 1;
    ll pos = 2;
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
    int n; 
    ll variants = 0, variants2 = 0;
    cin >> n;
    vector<int> movs = {5, 6, 7};
    for (int i=0; i<3; i++){
        variants += combinatory(n, movs[i]);
    }
    cout << variants << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();    
    return 0;
}