#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool checkString(string &str){
    for (int i=1; i<str.size(); i++){
        if (str[i] == str[i-1]) return false;
    }
    return true;
}

bool checkS(string &s, string &t){
    bool checkT = checkString(t); 
    for (int i=1; i<s.size(); i++){
        if (s[i] == s[i-1]) {
            if (!checkT || s[i] == t[t.size()-1] || s[i-1] == t[0]) return false;
            else continue;
        }
    }
    return true;
}

void solve() {
    int n, m;
    string s, t;
    cin >> n >> m;
    cin >> s >> t;
    bool check = checkS(s, t);
    if (check) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        solve();
    }
    return 0;
}