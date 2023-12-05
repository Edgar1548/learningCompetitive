#include <bits/stdc++.h>
using namespace std;
void solve(string str){
    if (str.size() <= 10){
        cout << str;
    } else {
        cout << str[0] << str.size()-2 << str[str.size()-1]; 
    }
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string str;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> str;
        solve(str);
    }
    return 0;
}
