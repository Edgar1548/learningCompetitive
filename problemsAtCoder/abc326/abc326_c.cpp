#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll M;
vector<ll> Avc;
void solve() { 
    cin >> N >> M;
    int maxDist = 0;
    Avc.resize(N);
    for (int i=0; i<N; i++) {
        cin >> Avc[i];
    }
    sort(Avc.begin(), Avc.end());
    for (int i=0; i<N; i++){
        auto low = lower_bound(Avc.begin()+i, Avc.end(), Avc[i]+M);
        maxDist = max((int)(low - (Avc.begin()+i)), maxDist);
    }
    cout << maxDist << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();    
    return 0;
}