#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll lastDigit(int d, ll b){
    if (b == 0) return 1;
    ll x = lastDigit(d, b/2)*lastDigit(d, b/2);
    if (b%2) x = x*d;
    if (x > 10){
        x = x%10;   
    }
    return x;
}

void solve(){
    int a; ll b;
    cin >> a >> b;
    if (a > 10) a = a%10;
    if (a == 0) cout << 0;
    else cout << lastDigit(a, b); 
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    cin >> t;
    for (int i=0; i<t; i++){
        solve();
    }
    return 0;
}      
