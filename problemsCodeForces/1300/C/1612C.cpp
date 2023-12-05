#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> vc;
unordered_map<int, int> dpMap;

ll calc(ll a){
    return ((a*(a+1))/2);
}
ll calc2(ll a, ll k){
    return (a*(k-1) - (a*(a-1))/2);
}

ll binarySearch2(ll k, ll left, ll rigth, ll base, ll k2){
    ll mid = (left + rigth)/2;
    if (calc2(mid, k2) + base == k) return mid; 
    else if(calc2(mid, k2) + base  <= k && calc2(mid+1, k2) + base >= k) return mid+1; 
    else if (calc2(mid, k2) + base < k) return binarySearch2(k, mid+1, rigth, base, k2);
    return binarySearch2(k, left, mid-1, base, k2);
}

ll binarySearch(ll k, ll left, ll rigth){
    ll mid = (left + rigth)/2;
    if (calc(mid) == k) return mid; 
    else if(calc(mid) <= k && calc(mid+1) >= k) return mid+1; 
    else if (calc(mid) < k) return binarySearch(k, mid+1, rigth);
    return binarySearch(k, left, mid-1);
}

void solve(ll k, ll x){
    ll a;
    if (calc(k) == x)
        cout << k << endl;   
    else if (calc(k) > x){
        a = binarySearch(x, 1, k);
        cout << a << "\n";
    }
    else {
        if (calc(k)+calc2(k-1, k) <= x){
            cout << 2*k-1 << "\n";
        }
        else {
            a = binarySearch2(x, 1, k-1, calc(k), k);
            cout << k + a << "\n";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    ll k, x;
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> k >> x;
        solve(k, x); 
    }
    return 0;
}      		     		 		 		