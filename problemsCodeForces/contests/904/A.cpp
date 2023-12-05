#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


bool findBeatiful(ll x, int k){
    int d;
    int sumDigits = 0;
    while(x > 0){
        d = x % 10;
        x -= d;
        x /= 10;
        sumDigits += d;
    }
    if (sumDigits%k == 0) return true;
    return false;
}
void solve(){
    ll x, y;
    int k;
    cin >> x >> k;
    while(true){
        if (findBeatiful(x, k)) break;
        x++;
    }
    cout << x << "\n";
}   
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        solve();
    }
    return 0;
}