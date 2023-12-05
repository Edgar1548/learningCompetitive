#include <bits/stdc++.h>
using namespace std;
void solve(int n){
    unordered_map<int, bool> mp;
    int x, y, tempX, tempY;
    cin >> x;
    for (int i=0; i<x; i++){
        cin >> tempX;
        mp[tempX] = true;
    }
    cin >> y;
    for (int i=0; i<y; i++){
        cin >> tempY;
        mp[tempY] = true;
    }
    if (mp.size() == n) cout << "I become the guy.";
    else cout << "Oh, my keyboard!";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n);
    return 0;
}