#include <bits/stdc++.h>
using namespace std;
void solve(int n){
    string love = "I love ";
    string hate = "I hate ";
    string res = "";
    for (int i=0; i<n; i++){
        if (i % 2 == 0){
            res += hate;
        } else res += love;
        if (i+1<n) res += "that ";
    }
    res += "it";
    cout << res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n);
    return 0;
}
