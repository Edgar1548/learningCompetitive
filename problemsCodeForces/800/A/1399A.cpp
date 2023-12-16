#include <bits/stdc++.h>
using namespace std;
bool checkArr(int n, int arr[]){
    for (int i=0; i<n-1; i++) {
        if (arr[i+1]-arr[i]>1) return false;
    };
    return true;
}
void solve(){
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    if (checkArr(n, arr)) cout << "YES";
    else cout << "NO";
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) solve();
    return 0;
}