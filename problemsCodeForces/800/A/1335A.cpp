#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, counter = 0;
    cin >> n;
    if (n > 2){
        if (n & 1 == 1){
            counter = n/2;
        } else counter = n/2-1;
    }
    cout << counter << "\n";
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