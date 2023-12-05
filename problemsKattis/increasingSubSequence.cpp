#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> vc;
unordered_map<int, int> dpMap;
unordered_map<int, pair<int, int>> wtf;
vector<vector<int>> mtDp(200, vector<int>(200));
pair<int, pair<int, int>> pairDp;
int dp(int i, int w, int val, int n)
{
    if (i == n + 1)
        return val;
    if (vc[i] <= vc[w]){
        return dp(i + 1, w, val, n);
    }
    int choose;
    if (dpMap[i] != -1){
        choose = val + dpMap[i];
    }
    else{
        choose = dp(i + 1, i, val + 1, n);
        dpMap[i] = choose - val;
    }
    mtDp[w][i] = choose - val + 1;
    if ((wtf[w].first == 0 || mtDp[w][i] > wtf[w].first || (wtf[w].first == mtDp[w][i] && vc[wtf[w].second] > vc[i])) && w != 0) wtf[w] = {mtDp[w][i], i};
    if ((mtDp[w][i] > pairDp.first || ((mtDp[w][i] == pairDp.first) && (vc[w] < vc[pairDp.second.first] || vc[i] < vc[pairDp.second.second]))) && w != 0){
        pairDp = {mtDp[w][i], {w, i}};
    }


    int noChoose = dp(i + 1, w, val, n);
    return max(choose, noChoose);
}

void solve(int n)
{
    pairDp = {0, {0, 0}};
    int dpValue = dp(0, 0, 0, n);
    cout << dpValue << " ";
    ll i = pairDp.second.first, j = pairDp.second.second;
    if (j == 0)
        cout << *min_element(vc.begin() + 1, vc.end()) << "\n";
    else{
        cout << vc[i] << " ";;
        while(wtf[j].first != 0){
            cout << vc[j] << " " ;
            j = wtf[j].second;
        }
        cout << vc[j] << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n != 0)
    {
        vc.push_back(-1);
        for (int i = 1; i <= n; i++)
        {
            ll temp;
            cin >> temp;
            vc.push_back(temp);
            wtf[i] = {0, 0};
            mtDp[i][i] = 1;
            dpMap[i] = -1;
        }
        solve(n);
        vc.clear();
        cin >> n;
    }
    return 0;
}