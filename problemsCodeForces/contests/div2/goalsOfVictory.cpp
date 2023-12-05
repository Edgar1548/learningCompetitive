#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, p; cin >> n >> p;
    
    for (int i=0; i<n-1; i++){
        cin >> elem;
        total += (-1)*elem;
    }
    cout << total << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    for (int i=0; i<t; i++){
        solve();
    }
    return 0;
}
