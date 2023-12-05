#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, m, status = 0;
    cin >> n >> m;
    string a(m, '#');
    string b(m-1, '.');
    for (int i=0; i<n; i++){
        if(i & 1 == 1){
            if (!status){
                cout << b << "#" << "\n";
                status = 1;
            } else {
                cout << "#" << b << "\n";
                status = 0;
            }
        } else {
            cout << a << "\n";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}