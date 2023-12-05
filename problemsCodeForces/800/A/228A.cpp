#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a, counter = 0;
    unordered_map<int, bool> mp;
    for (int i=0; i<4; i++){
        cin >> a;
        if (mp.find(a) != mp.end()){
            counter++;
        }
        mp[a] = true;
    }
    cout << counter;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
