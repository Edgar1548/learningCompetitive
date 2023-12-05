#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> vc;
ll binarySearch(ll k, ll left, ll rigth){
    ll mid = (left + rigth)/2;
    if (vc[mid] == k) return mid;
    else if(vc[mid] < k && vc[mid+1] >= k) return mid+1;
    else if (vc[mid] < k) return binarySearch(k, mid+1, rigth);
    return binarySearch(k, left, mid-1);
}

void solve(ll Q, ll N){
    if (vc[N-1] < Q) cout << 0;
    else if (vc[0] >= Q) cout << N;
    else {
        ll result = binarySearch(Q, 0, N-1);
        cout <<  N - result;
    }
    cout <<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll N, Q; 
    cin >> N; cin >> Q;
    for(int i=0; i<N; i++){
        ll tempA;
        cin >> tempA;
        vc.push_back(tempA);
    }
    sort(vc.begin(), vc.end());
    for (int i=0; i<Q; i++){
        ll tempQ;
        cin >> tempQ;
        solve(tempQ, N);
    }
    return 0;
}     