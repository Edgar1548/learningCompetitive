#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, bills = 0;
    cin >> n;
    int arr[5] = {100, 20, 10, 5, 1};
    if (n >= 100){
        bills += n/100;
        n %= 100;
    }
    while(n > 0){
        for (int j=0; j<5; j++){
            if (n >= arr[j]) {
                n -= arr[j];
                break;
            }
        }
        bills++;
    }
    cout << bills;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}