#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool checkArr(vector<int> &v, int limit){
    for (int i=0; pow(2, i)<pow(2, limit); i++){
        for (int j=pow(2,i); j<pow(2, i+1)-1; j++){
            if (j >= 2 && v[j] > v[j+1]) return false;
        }
    }
    for (int i=pow(2, limit)+1; i<v.size(); i++){
        if (v[i] < v[i-1]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> vc(n);
    int limitK = log2(n);
    for (int i=0; i<n; i++){
        cin >> vc[i];
    }
    bool check = checkArr(vc, limitK);
    if (check) cout << "YES\n";
    else cout << "NO\n";
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