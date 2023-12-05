#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    string a, b; cin >> a >> b;
    bool res = true;
    for (int i=0; i<n; i++){
        if (a[i] != b[i] && b[i] == 'C'){
            res = false;
            break;
        }
        else if (a[i] != b[i] && a[i] == 'C') continue;
        else if (a[i] != b[i] && a[i] == 'B'){
            if ( i-1 > 0 && a[i-1] == 'C' && b[i-1] == 'B') {
                swap(a[i-1], a[i]);
            }
            else if (i-1 < 0 || a[i-1] == 'A') {
                res = false;
                break;
            }
        }
        else if (a[i] != b[i] && a[i] == 'A'){
            if (i+1 < n && (a[i+1] == 'C' || a[i+1] == 'B') && b[i+1] == 'A') {
                swap(a[i], a[i+1]);
            }
            else if (i+1 >= n || a[i+1] == 'A') {
                res = false;
                break;
            }
        }
    }
    if (res) cout << "Yes";
    else cout << "No";
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
