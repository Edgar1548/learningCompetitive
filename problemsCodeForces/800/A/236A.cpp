#include <bits/stdc++.h>
using namespace std;
void solve(){
    string str;
    cin >> str;
    map<char, bool> mp;
    int counter = 0;
    for (int i=0; i<str.size(); i++){
        if (mp.find(str[i]) == mp.end()){
            mp[str[i]] = true;
            counter++;
        }
    }
    if (counter & 1 == 1) {
        cout << "IGNORE HIM!";
    } else {
        cout << "CHAT WITH HER!";
    }
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}