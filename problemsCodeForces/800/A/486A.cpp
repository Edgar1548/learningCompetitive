#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(ll n){
    ll res;
    res = n/2;
    if (n & 1 == 1){
        res++;
        res *= -1;
    } 
    cout << res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    solve(n);
    return 0;
}