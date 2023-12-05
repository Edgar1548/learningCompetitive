#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<char, int> counter;
int getTotalImpairs(){
    int count = 0;
    for (auto it: counter){
        if (it.second % 2 != 0) count++;
    }
    return count;
}

bool checkIsPossible(int res, int k, int N){
    int totalImpairs = getTotalImpairs(), totalSumPairs = N-totalImpairs;
    k -= totalImpairs;
    if (res % 2 == 0){
        if (k % 2 != 0 || k >= totalSumPairs || k < 0) return false;
        return true;
    } 
    k++;
    if (k <= totalSumPairs && k >= 0 && k%2 == 0) return true;
    return false;
}

void solve(){
    string s;
    int n, k, res;
    bool check = true;
    cin >> n >> k;
    cin >> s;
    res = n-k;
    for (int i=0; i<n; i++){
        if (counter.find(s[i]) == counter.end()) counter[s[i]] = 1;
        else counter[s[i]]++;
    }
    if (k >= n) check = false;
    else check = checkIsPossible(res, k, n);
    if (check) cout << "YES\n";
    else cout << "NO\n";
    counter.clear();
}   
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        solve();
    }
    return 0;
}