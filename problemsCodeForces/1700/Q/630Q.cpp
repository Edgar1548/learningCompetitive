#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
double PI = 3.14159265358979323846;
ld triangular(ld l){
    ld h = sqrt(2.0/3.0)*l;
    ld A = sqrt(3*l/2*pow(l/2, 3));
    return h*A;
}
ld cuadrangular(ld l){
    ld h = l/sqrt(2);
    ld A = l*l;
    return h*A;
}
ld pentagonal(ld l){
    ld a = l/(2*tan(PI/5));
    ld h = sqrt(pow(l,2) - pow(a, 2) - pow(l/2, 2));
    ld A = 5*l*(a)/2;
    return A*h;
}
void solve(){
    ld l1, l2, l3;
    cin >> l1 >> l2 >> l3;
    ld t = triangular(l1);
    ld c = cuadrangular(l2);
    ld p = pentagonal(l3);
    ld total = 1.0/3.0*(t+c+p);
    cout << setprecision(18) << total << "\n"; 
}   
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}   