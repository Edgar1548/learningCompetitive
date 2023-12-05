#include <bits/stdc++.h>
using namespace std;
void solve(int n){
    double total = 0;
    for (int i=0; i<n; i++){
        int p;
        cin >> p;
        total += p;
    }
    total = total/n;
    cout << setprecision(12) << total << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n);
    return 0;
}