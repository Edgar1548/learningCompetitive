#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> getKDigits(int n, int k){
    vector<int> a;
    return a;
}
string swapOrder(string &number){
    string newNumber = number;
    newNumber[1] = number[2];
    newNumber[2] = number[4];
    newNumber[4] = number[1];
    return newNumber;
}
void solve() {
    string number; 
    ll n, res = 0;
    ll modl = 1e5;
    cin >> number;
    number = swapOrder(number);
    n = stoi(number);
    res = n;
    for (int i=0; i<4; i++){
        res *= n;
        res %= modl;
    }
    if (res == 0) {
        cout << "00000\n";
    } else cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();    
    return 0;
}