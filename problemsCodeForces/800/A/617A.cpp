#include <bits/stdc++.h>
using namespace std;
void solve(int x){
    int counter = 0;
    counter += x/5;
    x %= 5;
    if (x != 0) counter++; 
    cout << counter << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x;
    cin >> x;
    solve(x);
    return 0;
}