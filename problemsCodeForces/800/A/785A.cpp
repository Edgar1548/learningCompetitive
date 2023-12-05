#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, counter = 0;
    cin >> n;
    unordered_map<string, int> mp;
    mp["Tetrahedron"] = 4;
    mp["Cube"] = 6;
    mp["Octahedron"] = 8;
    mp["Dodecahedron"] = 12;
    mp["Icosahedron"] = 20;
    for (int i=0; i<n; i++){
        string str;
        cin >> str;
        counter += mp[str];
    }
    cout << counter;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}