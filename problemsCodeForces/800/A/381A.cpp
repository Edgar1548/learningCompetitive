#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) cin >> arr[i];
    int l = 0, r = n-1;
    int s = 0, d = 0;
    int turn = 0;
    while(l <= r){
        int maxLR = max(arr[l], arr[r]);
        if (turn == 0){
            s += maxLR;
        } else d += maxLR;
        turn = turn == 0 ? 1 : 0;
        if (maxLR == arr[l]) l++;
        else r--;
    }
    cout << s << " " << d << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}