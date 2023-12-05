#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int binarySearch(ll &k, int l, int r, int &limitL, int &limitR){
    if (l > r) return -1;
    int mid = (l+r)/2;
    if (k + mid >= limitL && k + mid <= limitR) return mid;
    if (k + mid < limitL) return binarySearch(k, mid+1, r, limitL, limitR);
    return binarySearch(k, l, mid-1, limitL, limitR);
}

void find(int &a, int &b, int &c, ll m, int l, int r){
    for (a=l; a<=r; a++){
        if (m % a == 0) {
            b = l;
            c = l;
            return ;
        }
        ll j = a;
        ll expresion = j-m;
        while(expresion < r){ 
            if (expresion + r >= l){
                b = binarySearch(expresion, l, r, l, r);
                if (b != -1) {
                    c = expresion + b;
                    return;
                };
            }
            j += a;
            expresion = j-m;
        }
    }
}

void solve(){
    int l,r;
    ll m;
    cin >> l >> r >> m;
    int a, b, c;
    find(a, b, c, m, l, r);
    cout << a << " " << b << " " << c << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        solve();
    }
    return 0;
}      