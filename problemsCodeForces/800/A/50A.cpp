#include <bits/stdc++.h>
using namespace std;
void solve(int m, int n){
    if (m*n == 1) cout << 0;
    else cout << (m*n)/2; 
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m ,n;
    cin >> m >> n;
    solve(m, n);
    return 0;
}   
