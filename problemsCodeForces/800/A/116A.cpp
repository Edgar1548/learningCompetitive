#include <bits/stdc++.h>
using namespace std;
void solve(int n){
    int accum = 0, minCapacity = 0;
    for (int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        accum = accum - a + b;
        if (accum > minCapacity) minCapacity = accum;
    }
    cout << minCapacity;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n);
    return 0;
}