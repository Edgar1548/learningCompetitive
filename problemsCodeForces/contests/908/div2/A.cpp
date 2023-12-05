#include <bits/stdc++.h>
using namespace std;
#define maxL 1000000

char find_winner(string &str, int max_length, int Length_a, int Length_b){
    if (Length_a == str.size()) return 'A';
    if (Length_b == str.size()) return 'B';
    int y_a = 0, y_b = 0, x_a = 0, x_b = 0;
    for (int x=1; x<=max_length; x++){
        for (int i=0; i<str.size(); i++){
            if (str[i] == 'A') x_a++;
            else x_b++;
            if (x_a == x || x_b == x){
                if (x_a == x) y_a++;
                if (x_b == x) y_b++;
                x_a = 0;
                x_b = 0;
            }
            if (i == str.size()-1 && str[i] == 'B' && y_b > y_a) return 'B';
            if (i == str.size()-1 && str[i] == 'A' && y_a > y_b) {
                return 'A';
            }
        }
        y_a = 0;
        y_b = 0;
        x_a = 0;
        x_b = 0;
    }
    return '?';
}

void solve(){
    int n, max_length, l_a = 0, l_b = 0;
    string str;
    cin >> n; cin >> str;
    for (int i=0; i<str.size(); i++){
        if (str[i] == 'A') l_a++;
        else if (str[i] == 'B') l_b++;
    }
    max_length = max(l_a, l_b);
    char winner = find_winner(str, max_length, l_a, l_b);
    cout << winner << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) solve();
    return 0;
}  
