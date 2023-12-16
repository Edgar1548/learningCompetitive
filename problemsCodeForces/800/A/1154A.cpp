#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll arr[4];
    for (int i=0; i<4; i++) cin >> arr[i];
    sort(arr, arr+4);
    ll c = arr[3] - arr[0];
    ll b = arr[2] - c;
    ll a = arr[0] - b;
    cout << a << " " << b << " " << c << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}