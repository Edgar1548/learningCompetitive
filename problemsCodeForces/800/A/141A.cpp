#include <bits/stdc++.h>
using namespace std;
void solve(){
    string a, b, c;
    cin >> a >> b >> c;
    string temp = a + b;
    sort(temp.begin(), temp.end());
    sort(c.begin(), c.end());
    if (c == temp){
        cout << "YES";
    } else cout << "NO";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}