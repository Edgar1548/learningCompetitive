#include <bits/stdc++.h>
using namespace std;
void solve(int n){
    char aux = 0;
    int counter = 0;    
    for (int i=0; i<n; i++){
        char temp;
        cin >> temp;
        if (aux != temp) aux = temp;
        else counter++;
    }
    
    cout << counter << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n);
    return 0;
}
