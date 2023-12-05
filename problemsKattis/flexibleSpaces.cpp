#include <bits/stdc++.h>
using namespace std;
void solve(){
    int W, P, L;
    cin >> W; cin >> P;
    vector<int> vc;
    set<int> st;
    vc.push_back(0);    
    for (int i = 0; i < P; i++){
        cin >> L;
        vc.push_back(L);
    }
    vc.push_back(W);
    for (int i = 0; i < P + 2; i++){
        for (int j = i+1; j < P + 2; j++){
            st.insert(abs(vc[i] - vc[j]));
        }
    }
    for (auto i: st){
        cout << i << " ";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}      