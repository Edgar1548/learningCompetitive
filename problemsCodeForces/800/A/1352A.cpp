#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, i = 0;
    vector<int> vc;
    cin >> n;
    while(n > 0){
        if (n % 10 != 0){
            vc.push_back(n%10*pow(10, i));
            n -= n%10;
        }
        n /= 10;
        i++;
    }
    cout << vc.size() << "\n";
    for (auto it: vc){
        cout << it << " ";
    }
    cout << "\n";
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
