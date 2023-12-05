#include <bits/stdc++.h>
using namespace std;
void solve(int n){
    for (int i=0; i<n; i++){
        int a;
        cin >> a;
        if (a == 1) {
            isHard = true;
        }
    }
    if (isHard){
        cout << "HARD";
    } else cout << "EASY";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n);
    return 0;
}