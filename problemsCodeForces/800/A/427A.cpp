#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, data, recruits = 0, untreateds = 0; 
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> data;
        if (recruits + data < 0) {
            untreateds++;
            recruits = 0;
        } else recruits += data;
    }
    cout << untreateds;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}