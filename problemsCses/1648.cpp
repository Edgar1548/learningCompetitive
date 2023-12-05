#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxL 2*100000
ll t[2 * maxL];
ll a[maxL];

void build(int n){
    for (int i = 0; i < n; i++)  t[n + i] = a[i];    
    for (int i = n - 1; i >= 1; i--) t[i] = t[2 * i] + t[2 * i + 1];
}
void update(int pos, int val, int n){
    pos += n;
    t[pos] = val;
    while (pos > 1) {
        pos >>= 1;
        t[pos] = t[2 * pos] + t[2 * pos + 1];
    }
}
ll query(int left, int right, int n){
    left += n;
    right += n;
    //int mi = (int)1e8;
    ll sum = 0;
    while (left < right) {
        if (left & 1) {
            sum += t[left];
            left++;
        }
        if (right & 1) {
            right--;
            sum += t[right];
        }
        left /= 2;
        right /= 2;
    }
    return sum;
}

void solve(){
    int n, q, idx, l, r, op;
    ll val;
    cin >> n >> q;
    for (int i=0; i<n; i++) cin >> a[i];
    build(n);
    for (int i=0; i<q; i++){
        cin >> op;
        if (op == 1){
            cin >> idx >> val;
            update(idx-1, val, n);
        } else {
            cin >> l >> r;
            ll count = query(l-1, r, n);
            cout << count << "\n";
        }
        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}  
