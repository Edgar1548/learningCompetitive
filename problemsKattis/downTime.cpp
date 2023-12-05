#include <bits/stdc++.h>
using namespace std;
void solve(int n, int k){
    int lastStamp = 0; 
    int process = 1;
    int c = 1;
    vector<int> timeStamps(n);
    cin >> timeStamps[0];
    for (int i=1; i<n; i++){
        cin >> timeStamps[i];
        if (timeStamps[i] - timeStamps[lastStamp] < 1000){
            if (c == k){
                process++;
                c = 0;
            }
            c++;
        } else {
            lastStamp++;
        }
    }
    cout << process << "\n";

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; int k;
    cin >> n; cin >> k;
    solve(n, k);
    return 0;
}      