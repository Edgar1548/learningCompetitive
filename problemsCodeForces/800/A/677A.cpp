#include <bits/stdc++.h>
using namespace std;
void solve(int n, int h){
    int a, width = 0;
    for (int i=0; i<n; i++){
        cin >> a;
        if (a > h) width += 1;
        width++;
    }
    cout << width;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, h;
    cin >> n >> h;
    solve(n, h);
    return 0;
}