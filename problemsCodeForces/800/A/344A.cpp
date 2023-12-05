#include <bits/stdc++.h>
using namespace std;
void solve(int n){
    int counter = 0;
    string lastMagnet;
    for (int i=0; i<n; i++){
        string magnet;
        cin >> magnet;
        if (counter == 0 || lastMagnet[1] != magnet[1]){
            counter++;
            lastMagnet = magnet;
        } 
    }
    cout << counter;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n);
    return 0;
}