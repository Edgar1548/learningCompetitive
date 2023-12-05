#include <bits/stdc++.h>
using namespace std;
void solve(int n){
    if (n==1) cout << "1\n";
    else if (n%2 == 0){
        cout << n << " " << n-1 << " ";
        for (int i=2; i<=n-2; i+=2){
            cout << i << " " << (n-1)-i << " ";
        }
        cout << "\n";
    } else cout << "-1\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; int n;
    cin >> t;
    vector<int> test(t);
    for (int i=0; i<t; i++){
        cin >> n;
        solve(n);
    }
    return 0;
}      