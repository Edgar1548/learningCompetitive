#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, k, counter = 0, total = 240;
    cin >> n >> k;
    total -= k;
    while(total >= 0 && counter <= n){
        counter++;
        total -= 5*counter;
    }
    if (counter > 0) counter--;
    cout << counter;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
