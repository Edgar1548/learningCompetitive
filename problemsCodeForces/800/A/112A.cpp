#include <bits/stdc++.h>
using namespace std;

void solve(string str1, string str2){
    int res = 0;
    for (int i=0; i<str1.size(); i++){
        int temp1 = tolower(str1[i]), temp2 = tolower(str2[i]);
        if (temp1 < temp2){
            res = -1;
            break;
        } else if (temp1 > temp2){
            res = 1;
            break;
        }
    }
    cout << res << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string str1, str2;
    cin >> str1 >> str2;
    solve(str1, str2);
    return 0;
}   
