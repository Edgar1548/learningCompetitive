#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
struct Coordenate{
    ld x, y;
};
ld distance(Coordenate a, Coordenate b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void solve(){
    Coordenate P; cin >> P.x >> P.y;
    Coordenate A; cin >> A.x >> A.y;
    Coordenate B; cin >> B.x >> B.y;
    Coordenate Gen; Gen.x = 0; Gen.y = 0;
    ld dGenA = distance(Gen, A);
    ld dGenB = distance(Gen, B);
    ld dPA  = distance(P, A);
    ld dPB  = distance(P, B);
    ld dAB = distance(A,B);
    ld w;
    if (dGenA <= dGenB && dPA <= dPB){
        if (dGenA < dPA){
            w = dPA;
        } else w = dGenA;
    }
    else if (dGenB <= dGenA && dPB <= dPA){
        if (dGenB < dPB){
            w = dPB;

        } else w = dGenB;
    }
    else {
        ld minGen = min(dGenA, dGenB);
        ld minP = min(dPA, dPB);
        if (dAB/2 >= minGen && dAB/2 >= minP){
            w = dAB/2;
        } else if (minGen < minP){
            w = minP;
        } else {
            w = minGen;
        }
    }
    cout << setprecision(11) << w << "\n";

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
