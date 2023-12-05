#include <bits/stdc++.h>
using namespace std;
void solve(int n){
    if (n%2 == 0){
        for (int i=n-2; i>=1; i--){
            cout << i << " ";
        }   
    }
    else {
        cout << 1 << " " << 2 << " " << 3 << " ";   
        for (int i=n-2; i>=4; i--){
            cout << i << " ";
        }
    }
    cout << n-1 << " " << n << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; int n;
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> n;
        solve(n);
    }
    return 0;
}      
