#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int, int> ump;
ll modl = 1e9+7;
void compute(int top){
    ump[0] = 1;
    ump[1] = 1; 
    for (int i=2; i<=min(top, 1000000); i++){
        ump[i] = ((ump[i-1] % modl) * (i%modl)) % modl;
    }
}
ll po(int b, ll e){
    if (e == 0) return 1;
    else if (e == 1) return b%modl;
    ll x = (po(b, e >> 1));
    x = (x*x)%modl;
    if (e % 2) x = (x * b) % (modl);
    return  x;
}
ll combinatory(int n, int k){
    if (n <= k) return 1;
    ll res = 1, div = 1;
    res = ump[n];
    res *= ((po(ump[k], modl-2) % modl) * (po(ump[n-k], modl-2) % modl)) % modl;
    res %= modl;
    return res;
}
bool checkNumber(int numb, int a, int b){
    int ld = 0;
    while(numb > 0){
        ld = numb % 10;
        numb -= ld;
        numb /= 10;
        if (ld != a && ld != b) return false;
    }
    return true;
}
map<int, bool> mp;

void findNumbers(int i, int n, int a, int b, int minS, int maxS, int length){
    if (n >= minS) {
        if (i >= a*length && i<=b*length) mp[i] = true;
        if (n == maxS) return;
    }
    ll numb = i * 10;
    findNumbers(numb+a, n+1, a, b, minS, maxS, length);
    findNumbers(numb+b, n+1, a, b, minS, maxS, length);
}
void solve(){
    int a, b, n;
    ll total = 0;
    cin >> a >> b >> n;
    compute(n*b);
    findNumbers(a, 1, a, b, to_string(n*a).size(), to_string(n*b).size(), n);
    findNumbers(b, 1, a, b, to_string(n*a).size(), to_string(n*b).size(), n);
    for (int i=0; i<=n; i++){
        if (mp.find(i*a + (n-i)*b) != mp.end()){
            total += combinatory(n, i);
            total %= modl;
        }
    }
    cout << total;
}
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();   
    return 0;
}