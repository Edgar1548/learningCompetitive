#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
void solve(){
    int K;
    int coordX, coordY;
    int count;
    vector<pair<int, int>> coord;
    for (int i=0; i<3; i++){
        cin >> coordX; cin >> coordY;
        coord.push_back({coordX, coordY});
    }
    cout << 3 << endl;
    
    cout << coord[2].x + (coord[0].x - coord[1].x) << " ";
    cout << coord[2].y + (coord[0].y - coord[1].y) << endl;

    cout << coord[1].x + (coord[2].x - coord[0].x) << " ";
    cout << coord[1].y + (coord[2].y - coord[0].y) << endl;

    cout << coord[0].x + (coord[1].x - coord[2].x) << " ";
    cout << coord[0].y + (coord[1].y - coord[2].y) << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}       