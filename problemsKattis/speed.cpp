#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<pair<ld, ld>> vc;
ld inf = 1e6;
ld calculate(ld &c){
    ld res = 0;
    for (int i=0; i<vc.size(); i++){
        res += (vc[i].first) / (vc[i].second + c);
    }
    return res;
}

void solve(){
    int n, t; 
    ld di, si, res, mid;
    cin >> n >> t;
    ld high = 1e10;
    ld low = -inf;
    for (int i=0; i<n; i++){
        cin >> di >> si;
        vc.push_back({di, si});
        low = max(low, -si);
    }
    int count = 500;
    res = t+1;
    while(count && abs(res - t) > .00000001){
        count--;
        mid = (high + low)/2;
        res = calculate(mid);
        if (res > t) low = mid;
        if (res < t) high = mid;
    }
    cout << setprecision(9) << mid; 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}