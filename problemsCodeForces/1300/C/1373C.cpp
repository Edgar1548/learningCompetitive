#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string str;
    cin >> str;
    int val = 0, pos = 0;
    ll res = 0;
    for (int i=0; i<str.size(); i++){
        if (str[i] == '+') val++;
        else val--;
        if (val + pos < 0){
            res += i+1;
            pos++;
        }
    }
    res += str.size();
    cout << res << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        solve(); 
    }
    return 0;
}      		     		 		 		