#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool checkStr(string &str, int N){
    for (int i=1; i<N; i++){
        char chr = str[i];
        if (chr == 'a' && str[i-1] == 'b') return true;
        else if (chr == 'b' && str[i-1] == 'a') return true;
    }
    return false;
}

void solve() { 
    int N;
    string str;
    cin >> N;
    cin >> str;

    bool check = checkStr(str, N);
    if (check) cout << "Yes";
    else cout << "No";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();    
    return 0;
}