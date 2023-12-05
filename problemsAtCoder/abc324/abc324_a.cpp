#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;
    bool check = true;
    cin >> n;
    int temp = -1;
    for (int i=0; i<n; i++){
        int a;
        cin >> a;
        if (temp != -1 && a != temp) check = false;
        temp = a;
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