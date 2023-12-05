#include <bits/stdc++.h>
using namespace std;
void solve(){
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    if (arr[0] == arr[1] + arr[2] || arr[1] == arr[0] + arr[2] || arr[2] == arr[0] + arr[1]){
        cout << "YES";
    } else cout << "NO";
    cout << "\n";
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
