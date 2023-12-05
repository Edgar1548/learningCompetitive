#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    string str;
    cin >> str;
    n = str.size();
    int res = 0;
    if (str[0] == '1')  res += (n-1)%2 == 0 ? (n-1)/2 : (n-1)/2+1;
    if ((n-1)%2 == 0) {
        for (int i=1; i<n; i++){
            if (str[i] == '1') {
                res++;
                break;
            }       
        }
    }
    cout << res << endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}