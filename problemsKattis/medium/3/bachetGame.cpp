#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(int n) {
    int m;
    cin >> m;
    vector<int> vc(m);
    for(int i=0; i<m; i++){
        cin >> vc[i];
    }
    vector<int> vcWin(n+1, 0);
    for (int i=0; i<=n; i++){
        if (vcWin[i] == 0){
            for (int j=0; j<m; j++){
                if (i+vc[j] <= n) vcWin[i+vc[j]] = 1;
            }
        }
    }
    if(vcWin[n] == 0) cout << "Ollie Wins\n";
    else cout << "Stan Wins\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n){
        solve(n);
    }
    return 0;
}