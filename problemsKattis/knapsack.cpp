#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> umap;

void solve(int c, int n, int val[], int wgt[]){
    vector<vector<ll>> dpTable(n + 1, vector<ll>(c+1));
    int i = 0; int j = 0; int counter = 0;
    for (i = 0; i <= n; i++){
        for (j = 0; j <= c; j++){
            if (i == 0 || j == 0){
                dpTable[i][j] == 0;
            }
            else if (wgt[i - 1] <= j) {
                dpTable[i][j] = max(val[i-1] + dpTable[i-1][j - wgt[i-1]], dpTable[i-1][j]);
            }
            else {
                dpTable[i][j] = dpTable[i-1][j];
            }
        }
    }
    vector<int> vc;
    j--;
    while(n != 0){
        if (j != 0 && dpTable[n][j] != dpTable[n-1][j]){
            vc.push_back(n-1);
            j = j - wgt[n-1];
            counter++;
        };
        n--;
    }
    cout << counter << "\n";
    int size = vc.size();
    for(int i=0; i < size; i++){
        cout << vc[i] << "\n "[i + 1 < size];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int c, n;
    while(cin >> c >> n){
        int wgt[n]; int val[n];
        for (int i=0; i<n; i++){
            cin >> val[i];
            cin >> wgt[i];
        }
        solve(c, n, val, wgt);
    }
    return 0;
}      