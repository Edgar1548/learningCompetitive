#include <bits/stdc++.h>
using namespace std;
void solve(){
    int k, r;
    cin >> k >> r;
    int i;
    for (i=1; i<=10; i++){
        if ((k*i) % 10 == 0 || (k*i) % 10 == r) break;
    }
    cout << i << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
