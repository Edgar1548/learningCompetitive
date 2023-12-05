#include <bits/stdc++.h>
using namespace std;
void solve(int n, int k){
    while (k > 0){
        if (n % 10 == 0){
            n = n/10;
        } else n--;
        k--;
    }
    cout << n << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    solve(n, k);
    return 0;
}