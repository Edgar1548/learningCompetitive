#include <bits/stdc++.h>
using namespace std;
void solve(string a, string b){
    for (int i=0; i<a.size(); i++){
        if (a[i] != b[i]) cout << "1";
        else cout << "0";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a;
    cin >> b;
    solve(a, b);
    return 0;
}
