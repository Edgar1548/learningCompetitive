#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxSize = 1e3;
char arr[maxSize][maxSize];
ll testBorder(int start, int n){
    int y = start;
    ll steps = 0;
    for (int x=start, tempX = 0; x<n-1; x++){ 
        char temp[4];    
        temp[0] = arr[x][y];
        temp[1] = arr[n-1][x];
        temp[2] = arr[n-1-tempX][n-1];
        temp[3] = arr[y][n-1-tempX];
        /* cout << "temp:0 " << temp[0] << endl;
        cout << "temp:1 " << temp[1] << endl;
        cout << "temp:2 " << temp[2] << endl;
        cout << "temp:3 " << temp[3] << endl; */
        sort(temp, temp+4);
        steps += (temp[3] - temp[0]) + (temp[3] - temp[1]) + (temp[3] - temp[2]);
        tempX++;
    }   
    return steps;
}

void solve(){
    int n, start = 0;
    cin >> n;
    ll steps = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> arr[j][i];
        }
    }
    //cout << arr[0][5] << endl;
    while( n-start > 1){
        steps += testBorder(start, n);
        start++;
        n--;
    }
    cout << steps << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    for (int i=0; i<t; i++){
        solve();  
    }
    return 0;
}