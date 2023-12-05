#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> vc;
vector<int> dpMat;
void solve(int n){
    dpMat.resize(vc[n-2] +  vc[n-1]);
    bool dpBool = true;
    dpMat[0] = 0;
    for (int i=1; i<=vc[n-2] + vc[n-1] -1; i++){
        int maxJ;
        for (int j=0; j<n && vc[j] <= i; j++){
            if (dpMat[i] == 0) {
                dpMat[i] = 1 + dpMat[i-vc[j]];
            }
            else {
                dpMat[i] = min(dpMat[i], 1 + dpMat[i-vc[j]]);
            }
            maxJ = 1 + dpMat[i-vc[j]];
        }
        if (maxJ != dpMat[i]) {
            dpBool = false;
            break;
        }
    }
    if (dpBool) cout << "canonical";
    else cout << "non-canonical";
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        vc.push_back(temp);
    }
    solve(n);
    return 0;
}