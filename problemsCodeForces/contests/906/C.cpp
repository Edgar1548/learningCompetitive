#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<int, int> cantity(string &str){
    int ones = 0, zeros = 0;
    for (auto it: str){
        if (it == '1') ones++;
        else zeros++;
    }
    return {ones, zeros};
}

bool checkS(string &s, vector<int> &vc){
    auto cant = cantity(s);
    int ones = cant.first, zeros = cant.second;
    if (ones != zeros) return false;
    else {
        int size = s.size();
        for (int i=0; i<size; i++){
            if (s[i] == s[size - (i+1)] ){
                if (s[i] == '1') {
                    
                } else {
                    s.insert(size - (i+1)+1, "01");
                    vc.push_back(size - (i+1)+1);
                    size += 2;
                }
            } 
        }
        return true;
    }
}

void solve() {
    int n;
    vector<int> vc;
    string s;
    cin >> n;
    cin >> s;
    bool check = checkS(s, vc);
    if (check) {
        cout << vc.size() << "\n";
        if (vc.size() >= 1){
            for (auto it: vc){
                cout << it << " ";
            } cout << "\n";
        }
    } else cout << "-1\n";
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