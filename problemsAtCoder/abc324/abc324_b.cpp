#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n;
    cin >> n;
    bool check = true;
    while(check){
        if (n == 1) break;
        else if (n % 3 == 0 || n % 2 == 0){
            if (n % 3 == 0) n /= 3;
            if (n % 2 == 0) n /= 2; 

        } else {
            check = false;
        }
    }
    if (check) cout << "Yes";
    else cout << "No";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}