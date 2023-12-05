#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int findMinPath(int x, int y, int k){
    if (x > y) return x;
    int sum = x + k;
    if (sum > y) return y;
    return sum + 2*(y-sum);
}

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    int minPath = findMinPath(x, y, k);
    cout << minPath << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        solve();
    }
    return 0;
}