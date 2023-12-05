#include <bits/stdc++.h>
using namespace std;


void solve(){
    int i=0, j=0, n=8;
    char arr[n][n];
    bool isR = false, isB = false;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    while(!isR && !isB){
        if (arr[i][j] == 'R'){
            j++;
        } else if (arr[i][j] == 'B'){
            i++;
        }
        else {
            i++; j++;
        }
        if (i == n-1 && arr[i][j] == 'B') isB = true;
        else if (j == n-1 && arr[i][j] == 'R') isR = true; 
    }   
    cout << arr[i][j] << "\n";
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        solve();
    }
    return 0;
}