#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<int, vector<int>> ump; 
void preCalc(){
    ump[1] = {1,0};
    float act = 0;
    for (int i=2; i<1e3+1; i++){
        act = log10(2)*ump[i-1][0] + log10(11)*(ump[i-1][1]);
        if ((int)(act + log10(11)) + 1 == i){
            ump[i] = ump[i-1];
            ump[i][1]++;
        } else {
            ump[i] = ump[i-1];
            ump[i][0]++;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i=0; i<ump[n][0]; i++)
        cout << "2 ";
    
    for (int i=0; i<ump[n][1]; i++)
        cout << "11 ";
    cout << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    preCalc();
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        solve();
    }
    return 0;
}