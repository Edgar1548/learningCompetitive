#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(int n){
    int counter = 0;
    int m;
    unordered_map<int, int> check;
    vector<int> vc(n);
    for (int i=0; i<n; i++){
        cin >> m; 
        vc[i] = m;
        if (i+1 == vc[i]){
            int k;
            for (k=i-1; k>=0; k--){
                if (check[k] == true) {
                    k = -1;
                    break;
                }
                if (vc[k] > vc[i]) break;
            }
            if (k == -1) {
                check[i] = true;
                counter++;
            } ;
        }
    }
    cout << counter << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n);
    return 0;
}      