#include <bits/stdc++.h>
using namespace std;
void solve(){
    int t;
    int xa, ya;
    int xb, yb;
    int xf, yf;
    int maxX, minX;
    int maxY, minY;
    int moves;
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> xa; cin >> ya;
        cin >> xb; cin >> yb;
        cin >> xf; cin >> yf;
        maxX = max(xa, xb);
        minX = min(xa, xb);
        maxY = max(ya, yb);
        minY = min(ya, yb);
        
        int moves = (maxX - minX) + (maxY - minY);
        if ((xa == xb & xa == xf & minY < yf & yf < maxY) || (ya == yf & yb == yf & minX < xf & xf < maxX))
            moves += 2;

        cout << moves << endl;
        moves = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}      