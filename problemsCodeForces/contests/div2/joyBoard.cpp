/* #include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void dp(ll util, ll j, set<ll> &st){
    if (util <= j){
        st.insert(util);
        st.insert(0);
        return;
    } 
    st.insert(util);
    dp(util % j, j-1, st);
}

void solve(int t){
    ll n, m, k; cin >> n >> m >> k; 
    ll counter=0;
    if (k == 1){
        counter = 1;
    } else if (m > n){
        ll arr[m < 2*n-1 ? m%n:n-1];
        auto a = m < 2*n-1 ? m%n:n-1;
        cout << a << endl;
        for (ll i=0; i<= (m < 2*n-1 ? m%n:n-1); i++){
            set<ll> st;
            dp(i, n-1, st);
            arr[i] = st.size();
        }
        for (ll i=m; i>=n; i--){
            if (arr[i%n] + 1 == k) counter++;
        }
        if (k == 2) counter += n-1;
    } else if (k == 2) counter += m;
    cout << counter << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    for (int i=0; i<t; i++){
        solve(t);
    }
    return 0;
} */

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
void solve(int t){
    int n, m, k; cin >> n >> m >> k;
    int sizeDistinct, counter=0;
    if (k == 1) counter = 1;
    else if (n > m){
        if (k == 2) counter = m;
    } else {
        if (k == 2){
            counter += m/n - 1 + n;
        }
        if (k == 3){
            counter += (m-n) - (m/n - 1);
        }
    }
    cout << counter << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    for (int i=0; i<t; i++){
        solve(t);
    }
    return 0;
}
