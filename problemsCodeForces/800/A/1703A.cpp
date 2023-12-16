#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    char arr[3];
    string ans = "YES";
    bool check = true;
    for (int i=0; i<3; i++) {
        cin >> arr[i];
        if (toupper(arr[i]) != ans[i]) check = false;
    }
    if (check) cout << "YES";
    else cout << "NO";
    cout << "\n";


}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) solve();
    return 0;
}