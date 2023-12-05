#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    string str;
    cin >> str;
    string pref = "", suf = ""; 
    suf += str[str.size()-1];
    pref += str[0];
    int i = 1, j = str.size()-2;
    while(pref.size() < str.size()){
        if (pref == suf){
            cout << pref.size() << " ";
        }
        pref += str[i];
        string tmp = str[j] + suf;
        suf = tmp;
        i++;
        j--;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}