#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
void solve(){
    ld e = 1.000000011;
    ld n, t;
    cin >> n >> t;
    ld total = n * pow(e, t);
    cout << setprecision(29) << total;
}   
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}