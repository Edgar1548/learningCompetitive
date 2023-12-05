#include <bits/stdc++.h>
using namespace std;
void solve(int n){
    if (n == 2) cout << "NO";
    else {
        if (n & 1 == 1){
            cout << "NO";
        } else cout << "YES";
    } 
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n);
    return 0;
}
