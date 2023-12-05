#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int, bool> isPossible;
unordered_map<int, ll> counter;
ll modl = 1e9+7;
void solve(int n){
    for (int i = 1; i <= n*n; i++){
        if (isPossible[i+1] && i%n != 0) counter[i+1] = (counter[i+1] + counter[i])%modl;
        if (isPossible[i+n] && (i+n)<=n*n) counter[i+n] = (counter[i+n] + counter[i])%modl;
    }
    ll total = counter[n*n];
    cout << total << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int numb = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            char temp;
            cin >> temp;
            if (temp == '*'){
                isPossible[numb] = false;
            }
            else isPossible[numb] = true;
            counter[numb] = 0;
            numb++;
        }
    }
    if (isPossible[1]) counter[1] = 1;
    solve(n);
    return 0;
}