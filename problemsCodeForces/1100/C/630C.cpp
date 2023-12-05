#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
ll power(ll x, unsigned int y){
    ll res = 1;
    while (y > 0) {
        if (y & 1)
            res = res * x;
        y = y >> 1; 
        x = x * x;
    }
    return res;
}

void solve(){
    ll n;
    cin >> n;
    ll total = 0;
    for (int i=0; i< n; i++){
        total += power(2, i);
    }
    total *= 2;
    cout << total << "\n";
}   
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}