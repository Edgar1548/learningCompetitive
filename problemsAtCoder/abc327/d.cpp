#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() { 
    int N, M;
    cin >> N >> M;
    int a[M];
    int b[M];
    vector<int> x(N+1, -1);
    bool check = true;
    for (int i=0; i<M; i++) cin >> a[i];
    for (int i=0; i<M; i++) cin >> b[i];
    for (int i=0; i<M; i++){
        int ai = a[i];
        int bi = b[i];
        if (ai == bi) check = false;
        if (x[ai] == -1 && x[bi] == -1){
            x[ai] = 1;
            x[bi] = 0;
        } else if (x[ai] == -1){
            if (x[bi] == 0) x[ai] = 1;
            else x[ai] = 0;
        } else if (x[bi] == -1){
            if (x[ai] == 0) x[bi] = 1;
            else x[bi] = 0;
        } else if (x[ai] == x[bi]){
            cout << ai << bi << endl;
            check = false;
        }
    }
    if (check) cout << "Yes";
    else cout << "No";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();    
    return 0;
}