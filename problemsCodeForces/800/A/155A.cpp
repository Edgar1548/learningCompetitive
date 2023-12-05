#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, data, minC, maxC, counter = 0;
    cin >> n;
    cin >> data;
    minC = data; maxC = data;
    for (int i=1; i<n; i++){
        cin >> data;
        if (data > maxC) {
            counter++;
            maxC = data;
        }
        if (data < minC){
            counter++;
            minC = data;
        }
    }
    cout << counter;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}