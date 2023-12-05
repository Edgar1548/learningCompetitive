#include <bits/stdc++.h>
using namespace std;
void solve(int t){
    int a, b;
    for (int i=0; i<t; i++){
        cin >> a >> b;
        if (a/b < 1) cout << b-a << "\n";
        else {
            cout << (int)(ceil((double)a/(double)b)*b - a) << "\n";
        }
    }   
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    solve(t);
    return 0;
}
