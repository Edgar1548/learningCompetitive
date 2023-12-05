#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s;
    cin >> s;
    int counterN = count(s.begin(), s.end(), 'N');
    if (counterN == 1) cout << "NO\n";
    else cout << "YES\n";
}   
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) solve();
    return 0;
}