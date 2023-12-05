#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin >> n;
    unordered_map<int, bool> mp;
    int temp;
    bool checked = true;
    for (int i=0; i<n; i++){
        cin >> temp;
        if (mp.find(temp) == mp.end()){
            mp[temp] = true;
        } else checked = false;
    }
    if (checked) cout << "YES";
    else cout << "NO";
    cout << "\n";
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        solve(n);
    }
    return 0;
}