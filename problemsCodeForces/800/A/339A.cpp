#include <bits/stdc++.h>
using namespace std;
void solve(){
    vector<char> vc;
    string str;
    cin >> str;
    for (int i =0; i<str.size(); i++){
        if (str[i] != '+') {
            vc.push_back(str[i]);}
    }
    sort(vc.begin(), vc.end());
    for (int i=0; i<vc.size(); i++){
        cout << vc[i] << "+ "[i+1>=vc.size()];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
