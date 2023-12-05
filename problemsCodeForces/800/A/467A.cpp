#include <bits/stdc++.h>
using namespace std;
void solve(int n){
    int counter = 0;
    for (int i=0; i<n; i++){
        int p, q;
        cin >> p >> q;
        if (q - p >= 2) counter++;
    }
    cout << counter;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n);
    return 0;
}