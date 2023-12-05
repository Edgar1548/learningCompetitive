#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Step{
    ll heigth, totalHeigth;
};

int binarySearch(vector<Step> &arr, ll x){
    int lo = 1, hi = arr.size()-1;
    while(lo <= hi){
        int m = (lo + hi)/2;
        if (arr[m].heigth == x) return m+1;
        if (arr[m].heigth > x && arr[m-1].heigth <= x) return m;
        else if (x < arr[m].heigth) hi = m-1;
        else{lo = m+1;}
    }
    return hi+1;
}

void solve(){
    ll n, q, heigth, totalHeigth = 0, maxHeigth = 0, res;
    cin >> n >> q;
    vector<Step> arr;
    for (int i=0; i<n; i++){
        cin >> heigth;
        totalHeigth += heigth;
        if (heigth > maxHeigth){
            maxHeigth = heigth;
            Step aux;
            aux.heigth = heigth;
            aux.totalHeigth = totalHeigth;
            arr.push_back(aux);
        }
    }
    for (int i=0; i<q; i++){
        cin >> heigth;
        if (heigth < arr[0].heigth) res = 0;
        else if (heigth >= arr[arr.size()-1].heigth) res = totalHeigth;
        else {
            int pos = binarySearch(arr, heigth);
            res = arr[pos].totalHeigth - arr[pos].heigth;
        }
        cout << res << " ";
    }
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    for (int i=0; i<t; i++){
        solve();
    }
    return 0;
}
