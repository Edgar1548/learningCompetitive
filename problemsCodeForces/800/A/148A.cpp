#include <bits/stdc++.h>
using namespace std;
void solve(){
    int arr[4], n, res = 0;
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> n;
    if (arr[0] == 1 || arr[1] == 1 || arr[2] == 1 || arr[3] == 1)  res = n;
    else {
        for (int i=1; i<=n; i++){
            for (int j=0; j<4; j++){
                if (i % arr[j] == 0) {
                    res++;
                    break;
                }
            }
        }
    }
    cout << res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
