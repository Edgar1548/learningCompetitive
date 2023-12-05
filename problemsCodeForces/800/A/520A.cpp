#include <bits/stdc++.h>
using namespace std;
void solve(int n){
    string str;
    cin >> str;
    int counter = 0;
    unordered_map<char, bool> mp;
    for (int i=0; i<n; i++){
        if (mp.find(str[i]) == mp.end()){
            mp[(char)tolower(str[i])] == true;
            mp[(char)toupper(str[i])] == false;
            counter++;
        }
    }
    if (counter == 26){
        cout << "YES";
    }else cout << "NO";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n);
    return 0;
}