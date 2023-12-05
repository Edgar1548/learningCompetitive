#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> umap;
unordered_map<ll, ll> umap2;
vector<ll> elmts;
ll maxI = 2e9;
ll binarySearch(ll k, int left, int rigth){
    int mid = (left + rigth)/2;
    if (elmts[mid] == k) return mid;
    else if(elmts[mid] < k && elmts[mid+1] >= k) return mid+1;
    else if (elmts[mid] <= k) return binarySearch(k, mid+1, rigth);
    return binarySearch(k, left, mid-1);
}

void precalculate(){
    ll m = 1;
    ll i;
    for (i = 1; i<=maxI; i+=m){
        umap[i] = m;
        elmts.push_back(i);
        m++;
    }
    elmts.push_back(i);
    umap[i] = m;
}
void solve(){
    ll n, k, idx, m;
    cin >> n; cin >> k;
    string na2b(n, 'a');
    if (k >= elmts[elmts.size()-1] || k < elmts[0]){
        cout << "ga" << endl;
    }
    idx = binarySearch(k, 0, elmts.size()-1);
    m = umap[elmts[idx]];
    na2b[(n-1) - m] = 'b';
    na2b[(n-1) - (m - 1 - (elmts[idx]-k))] = 'b';
    cout << na2b << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    precalculate();
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        solve();
    }
    return 0;
}      	  		 		 		