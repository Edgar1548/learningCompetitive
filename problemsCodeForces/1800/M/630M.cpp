#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() 
{
    ll x;
    cin >> x;
    vector<pair<ll, int>> counts(4);
    for (int i = 0; i < 4; i++)
    {
        ll desv;
        desv = -1 * x;
        desv += 90 * i;
        desv = abs(desv);
        desv %= 360;
        if (desv > 180) desv = 360 - desv;
        counts[i] = make_pair(desv, i);
    }
    
    sort(counts.begin(), counts.end());
    cout << counts[0].second;
}
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();   
    return 0;
}