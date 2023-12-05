#include <bits/stdc++.h>
using namespace std;
void solve(){
    string str;
    cin >> str;
    bool check = true;
    for (int i=1; i<16; i+=2){
        if (str[i] == '1') {
            check = false;
            break;
        }
    }
    if (check) cout << "Yes";
    else cout << "No";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
