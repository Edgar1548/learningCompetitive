#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a, b, daysDifferent, daysEqual;
    cin >> a >> b;
    int temp = max(a,b) - min(a,b);
    daysDifferent = min(a,b);
    daysEqual = (temp >= 2 ? temp/2 : 0);
    cout << daysDifferent << " " << daysEqual; 

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
