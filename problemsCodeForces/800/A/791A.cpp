#include <bits/stdc++.h>
using namespace std;
void solve(int a, int b){
    int counter = 0;
    while(a < b || a == b){
        counter++;
        a *= 3;
        b *= 2;
    }
    cout << counter << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    solve(a, b);
    return 0;
}