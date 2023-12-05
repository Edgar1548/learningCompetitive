#include <bits/stdc++.h>
using namespace std;
void solve(int n, int contador){
    vector<int> vc_n;
    int test_n;
    int test_m;
    for(int i=0; i<n; i++){
        cin >> test_n;
        vc_n.push_back(test_n);
    }
    vector<int> sums;
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            sums.push_back(vc_n[i] + vc_n[j]);
        }
    }
    int min;
    int m;
    cin >> m;
    cout << "Case " << contador << ":" << "\n"; 
    for (int i=0; i<m; i++){
        cin >> test_m;
        min = sums[0];
        for (int j=0; j<size(sums); j++){
            if ( abs(test_m - min) > abs(test_m - sums[j])){
                min = sums[j];
            }
        }
        cout << "Closest sum to " << test_m << " is " << min << "." << "\n";
    }

}
int main(){
    //ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int contador = 1;
    while(cin >> n){
        solve(n, contador);
        contador++;
    }
    return 0;
}      