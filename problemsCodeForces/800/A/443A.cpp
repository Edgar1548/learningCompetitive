#include <bits/stdc++.h>
using namespace std;
void solve(){
    string str;
    getline(cin, str);
    int counter = 0;
    unordered_map<char, bool> mp;
    if (str.size() > 2){
        for (int i=1; i<=str.size()-1; i+=3){
            if (mp.find(str[i]) == mp.end()){
                counter++;
                mp[str[i]] == true; 
            }
        }  
    } 
    cout << counter;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
