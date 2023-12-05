#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(multiset<ll> ms, int n){
    auto end = ms.rbegin();
    auto begin = ms.begin();
    ll ans = max((*begin)*(*(++begin)), (*end)*(*(++end)));
    cout << ans << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; int n; ll m;
    cin >> t;
    for(int i=0; i<t; i++){
        multiset<ll> ms;
        cin >> n;
        for (int i=0; i<n; i++){
            cin >> m; 
            ms.insert(m);
        }
        solve(ms, n);
    } 
    return 0;
}      
