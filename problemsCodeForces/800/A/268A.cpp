#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, res = 0;
    cin >> n;
    int arr[n][2];
    unordered_map<int, int> mp;
    for (int i=0; i<n; i++){
        cin >> arr[i][0] >> arr[i][1];
        if (mp.find(arr[i][1]) == mp.end()){
            mp[arr[i][1]] = 1;
        } else mp[arr[i][1]]++;
    }
    for (int i=0; i<n; i++){
        if (mp.find(arr[i][0]) != mp.end()){
            res += mp[arr[i][0]];
        }
    }
    cout << res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
