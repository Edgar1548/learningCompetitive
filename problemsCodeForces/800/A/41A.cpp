#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(string from, string to){
    bool isCorrect = true;
    int j = 0;
    for (int i=from.size()-1; i>=0; i--){
        if (from[i] != to[j]){
            isCorrect = false;
            break;
        }
        j++;
    }
    if (isCorrect) cout << "YES";
    else cout << "NO";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string from, to;
    cin >> from >>  to;
    solve(from, to);
    return 0;
}