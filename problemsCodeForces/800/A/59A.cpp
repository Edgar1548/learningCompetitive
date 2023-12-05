#include <bits/stdc++.h>
using namespace std;
void solve(){
    string str;
    int lowerCount;
    cin >> str;
    for (int i=0; i<str.size(); i++){
        if ((char)tolower(str[i]) == str[i]) lowerCount++;
    }
    if (str.size() - lowerCount > lowerCount){
        for (int i=0; i<str.size(); i++){
            cout << (char)toupper(str[i]);
        }
    }
    else {
        for (int i=0; i<str.size(); i++){
            cout << (char)tolower(str[i]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}