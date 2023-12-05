#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxL 200
int arr[maxL+1];
int res[maxL+1];
void solve(){
    int n, tmp, size;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i+1];
    }
    for (int i=0; i<n; i++){
        tmp = arr[i+1];
        size = 1;
        while(i+1 != tmp){
            tmp = arr[tmp];
            size++;
        }
        res[i] = size;
    }
    for (int i=0; i<n; i++) cout << res[i] << " ";
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        solve();
    }
    return 0;
}