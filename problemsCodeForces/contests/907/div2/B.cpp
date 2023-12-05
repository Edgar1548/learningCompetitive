#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxL 100006
unordered_map<int, ll> ump;
ll a[maxL]; 
void compute(){
    for (int i=1; i<31; i++) ump[i] = -1;
    ump[0] = 0;
}
int findExp(ll k, unordered_map<int, ll> &mp){
    int exp = log2(k);
    ll po = (1 << exp);
    while(k % po != 0 || mp[exp] == -1){
        exp--;
        po = (1 << exp);
        if (exp == 0) return -1;
    }
    return exp;
}
void solve() {
    int n, q, x;
    cin >> n >> q;
    int temp = 31;
    unordered_map<int, ll> mp = ump;
    vector<int> tempX;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<q; i++) {
        cin >> x;
        if (x < temp){  
            temp = x;
            tempX.push_back(x);  
        }
    }
    mp[tempX[tempX.size()-1]] = (1 << tempX[tempX.size()-1]-1);
    for (int i=tempX.size()-2; i>=0; i--){
        int poss = tempX[i+1];
        mp[tempX[i]] = mp[poss] | (1 << tempX[i]-1);
    }
    for (int i=0; i<n; i++) {
        ll add = a[i];
        if (a[i] % 2 == 0){
            int exp = findExp(a[i], mp);
            if (exp != -1) add |= mp[exp];
        }
        cout << add << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    compute();
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        solve();
    }
    return 0;
}