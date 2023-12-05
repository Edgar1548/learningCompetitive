#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modl = 1e9+7;
ll po(ll b, ll e){
    if (e == 0) return 1;
    ll res = 1;
    while(e){
        if (e & 1) res = res * b % modl;
        b = b * b % modl;
        e >>= 1;
    }
    return res;
}
void solve() {
    int n; cin >> n;
    ll numbDiv = 1, numbDiv2 = 1, sumatory = 1, mult = 1;
    vector<vector<ll>> vc(n, vector<ll>(2));
    for (int i=0; i<n; i++){
        cin >> vc[i][0] >> vc[i][1];
        numbDiv = numbDiv * (vc[i][1] + 1) % modl;
        sumatory = sumatory * (po(vc[i][0], vc[i][1] + 1) - 1) % modl * 
                    po(vc[i][0]-1, modl-2) % modl;
        mult = po(mult, vc[i][1] + 1) * 
                    po(po(vc[i][0], (vc[i][1] * (vc[i][1] + 1) / 2)), numbDiv2) % modl;
		numbDiv2 = numbDiv2 * (vc[i][1] + 1) % (modl-1);
    }
    cout << numbDiv << ' ' << sumatory << ' ' << mult;
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}