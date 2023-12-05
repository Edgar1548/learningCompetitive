#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[3];
bool checker(int i, int &k){
    while(arr[i] != arr[0] && k > 0){
        arr[i] -= arr[0];
        k--;
        if (arr[i] < arr[0]) {
            return false;
        }
    }
    if (arr[i] != arr[0]) return false;
    return true;
}

void solve(){
    cin >> arr[0] >> arr[1] >> arr[2];
    bool check = true;
    sort(arr, arr+3);
    int k = 3;
    check = (checker(1, k) && checker(2, k));
    cout << (check ? "YES" : "NO") << "\n"; 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    for (int i=0; i<t; i++){
        solve();  
    }
    return 0;
}