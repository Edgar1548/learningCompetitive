#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() { 
    int N = 9;
    int arr[N][N];
    bool check = true;
    vector<unordered_map<int, bool>> row(9);
    vector<unordered_map<int, bool>> col(9);
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> arr[i][j]; 
            if (row[i].find(arr[i][j]) != row[i].end()){
                check = false;
            } else row[i][arr[i][j]] = true;
            if (col[j].find(arr[i][j]) != col[j].end()){
                check = false;
            } else col[j][arr[i][j]] = true;
        }
    }
    unordered_map<int, bool> square;
    for (int i=0; i<N; i+=3){
        for (int j=0; j<N; j+=3){
            auto tmp = square;
            for (int row=0; row<3; row++){
                for (int col=0; col<3; col++){
                    int x = j + col, y = i + row;
                    if (tmp.find(arr[x][y]) == tmp.end()) tmp[arr[x][y]] = true;
                    else check = false;
                }
            }
        }
    }
    if (check) cout << "Yes";
    else cout << "No";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();    
    return 0;
}