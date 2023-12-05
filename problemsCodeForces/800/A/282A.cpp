#include <bits/stdc++.h>
using namespace std;
void solve(int n){
    string str;
    int count = 0;
    for (int i=0; i<n; i++){
        cin >> str;
        for (int j=0; j<str.size(); j++){
            if (str[j] == '+') count++;
            else if (str[j] == '-') count--;
            if (str[j] != 'X') break; 
        }
    }
    cout << count <<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n);
    return 0;
}
