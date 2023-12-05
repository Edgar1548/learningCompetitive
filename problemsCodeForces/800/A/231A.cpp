#include <bits/stdc++.h>
using namespace std;
void solve(int n){
    int res = 0;
    for (int i=0; i<n; i++){
        int counter = 0;
        for (int j=0; j<3; j++){
            int temp;
            cin >> temp;
            if (temp == 1) counter++;
        }
        if (counter >= 2) res++;
    }
    cout << res << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n = 0, count = 0;
    cin >> n;
    solve(n);
    return 0;
}