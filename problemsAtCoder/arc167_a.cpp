#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int N, M;   
    cin >> N >> M;
    ll res = 0;
    vector<int> Avc(N);
    for (int i=0; i<N; i++){
        cin >> Avc[i];
    }
    sort(Avc.begin(), Avc.end());
    int k = N - M;
    if (k != 0) {
        for (int st = 0; st < k; st++){
            res += pow(Avc[st] + Avc[N - (M-k) - 1 - st], 2);
        }
    }
    for (int st=N - (M-k); st<Avc.size(); st++){
        res += pow(Avc[st], 2);
    }
    cout << res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}