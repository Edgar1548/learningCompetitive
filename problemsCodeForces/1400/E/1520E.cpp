#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    string str;
    vector<int> pos;
    int n; 
    ll res = 0; 
    cin >> n;
    cin >> str;
    for (int i=0; i<n; i++){
        if (str[i] == '*') pos.push_back(i);
    }
    int mid = (0 + pos.size())/2;
    for (int i=0; i<pos.size(); i++){
        res += abs(pos[i]-pos[mid]) - (abs(i - mid)); 
    }
    cout << res << "\n";

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        solve();
    }
    return 0;
}      