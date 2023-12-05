#include <bits/stdc++.h>
using namespace std;
int arr[5][5];
void solve(int posi, int posj){
    int dist = abs(posi-3) + abs(posj-3);
    cout << dist << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int posi, posj;
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            cin >> arr[i][j];
            if (arr[i][j] == 1){
                posi = i+1;
                posj = j+1;
            } 
        }
    }
    solve(posi, posj);
    return 0;
}   
