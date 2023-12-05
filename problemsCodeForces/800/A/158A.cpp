#include <bits/stdc++.h>
using namespace std;
void solve(int n, int k){
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    int elem = arr[k-1];
    int i;
    for (i=0; i<n; i++){
        if (arr[i] < elem || arr[i] <= 0) break;
    }
    cout << i << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    solve(n, k);
    return 0;
}
