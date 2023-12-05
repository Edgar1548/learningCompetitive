#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n, k, res = 0;
    bool check = true;
    cin >> n;
    vector<int> vc(n);
    for (int i=0; i<n; i++) cin >> vc[i];
    sort(vc.begin(), vc.end());
    for (k=1; k<=(n%2==0?n/2:n/2+1); k++){
        check = true;
        int pos = k-1;
        for (int i=k; i>=1; i--){
            if (vc[pos] > k-i+1){
                check = false;
                break;
            } 
            pos++;
        }
        if (check) res++;
        else break;
    }
    cout << res << "\n"; 
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