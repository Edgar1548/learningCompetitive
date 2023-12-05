#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
double PI = 3.14159265358979323846;
ld rad(ld deg){
    return PI*deg/180.0;
}
void solve(){
    ll n, r;
    cin >> n >> r;
    ld sin_x = sin(PI - 3*PI/(2*n)); 
    ld sin_90 = sin(PI/(2*n));
    ld sin_180 = sin(PI/n);
    ld total = n / sin_x * sin_180 * sin_90 *  r * r;
    cout << setprecision(15) << total;
}   
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}