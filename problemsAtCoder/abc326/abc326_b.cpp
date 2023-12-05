#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool exploreDigits(int n){
    int ld = 0;
    vector<int> digits;
    while(n > 0){
        ld = n%10;
        n -= ld;
        n /= 10;
        digits.push_back(ld);
    }
    if (digits[2]*digits[1] == digits[0]) return true;
    return false;
}
void solve() {
    int N, top;
    cin >> N;
    for(top=N; top<=919; top++){
        if (exploreDigits(top)) break;
    }
    cout << top << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();    
    return 0;
}