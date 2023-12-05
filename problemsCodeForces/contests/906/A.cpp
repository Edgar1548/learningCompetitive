#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> vc;
vector<int>::iterator bs(int k){
    if (k <= 0) return vc.end();
    auto it = lower_bound(vc.begin(), vc.end(), k);
    return it;
}
bool rec(int a, int b, vector<bool> visiteds, int count){
    if (count == visiteds.size()) return true;
    int val = vc[a] + vc[b];
    while(count != visiteds.size()){
        auto it = bs(val - vc[b]);
        int pos = distance(vc.begin(), it);
        while(visiteds[pos] && pos < visiteds.size()) pos++;
        if (pos == visiteds.size() || vc[pos] != val - vc[b]) return false;
        visiteds[pos] = true;
        b = pos;
        count++;
    }
    return true;
}
void solve() {
    int n;
    bool check = false;
    cin >> n;
    vc.resize(n);
    vector<bool> visiteds(n);
    unordered_map<int, bool> chekeds;
    for (int i=0; i<n; i++) cin >> vc[i];
    sort(vc.begin(), vc.end());
    for (int i=0; i<n && !check; i++) {
        if (chekeds.find(vc[i]) == chekeds.end()) {
            chekeds[vc[i]] = true;
        } else continue;
        visiteds[i] = true;
        for (int j=0; j<n && !check; j++){
            if (j != i){
                visiteds[j] = true;
                check = rec(i, j, visiteds, 2);
                visiteds[j] = false;
            }
        }
        visiteds[i] = false;
    }
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