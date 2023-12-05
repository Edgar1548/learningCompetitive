#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n, x;
    ll count = 0;
    cin >> n;
    string s[n];
    vector<vector<int>> mp(n, vector<int>(6));
    vector<vector<ll>> cnt_mp(6, vector<ll>(50, 0));
    for (int i=0; i<n; i++) {
        cin >> s[i];
        int progressive = 0;
        for (x=1; x<=s[i].size(); x++){
            progressive += (s[i][x-1] - '0');
            mp[i][x] = progressive;
        }
        cnt_mp[x-1][progressive]++;
    }
    for (int i=0; i<n; i++){
        int i_size = s[i].size();
        for (int j=i_size; j>=1; j--){
            int temp_mp = mp[i][j];
            int left = i_size - j;
            int left_mp = mp[i][i_size] - mp[i][j];
            ll left_cnt_mp = 0;
            auto ump = cnt_mp[abs(j-left)];
            int k = abs(temp_mp-left_mp);
            if ((j < left && temp_mp < left_mp) || (j > left && temp_mp > left_mp)){
                left_cnt_mp = ump[k];
            }
            count += left_cnt_mp;
        }
    }
    cout << count << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}