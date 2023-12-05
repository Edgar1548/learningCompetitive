#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(ll n){
    int counterLucky = 0;
    bool isLucky = true;
    while(n > 0){
        int lastDigit = n % 10;
        if (lastDigit == 4 || lastDigit == 7) counterLucky++;
        n -= lastDigit;
        n /= 10;
    }
    if (counterLucky == 0) isLucky = false;
    while(counterLucky > 0){
        int lastDigit = counterLucky % 10;
        if (counterLucky != 4 && counterLucky != 7) {
            isLucky = false;
            break;
        }
        counterLucky -= lastDigit;
        counterLucky /= 10;
    }
    if (!isLucky){
        cout << "NO";
    } else cout << "YES";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    solve(n);
    return 0;
}