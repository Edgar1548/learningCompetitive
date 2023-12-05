#include <bits/stdc++.h>
using namespace std;
void solve(int n){
    int counter = 0;
    int arr[n+1];
    for (int i=1; i<=n; i++){
        int pos;
        cin >> pos;
        arr[pos] = i;
    }
    for (int i=1; i<=n; i++){
        cout << arr[i] << " ";
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