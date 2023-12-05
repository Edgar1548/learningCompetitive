#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, first = 0, second = 0;
    cin >> n;
    vector<int> a(n);
    int tmp = 0;
    unordered_map<int, int> counter;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (counter.find(a[i]) == counter.end()) {
            counter[a[i]] = 1;
        } else counter[a[i]]++;
    }
    for (auto it: counter){
        if (it.second > 1){ 
            tmp++;
            if (first == 0) first = it.first;
            else if (first != 0 && second == 0) second = it.first;
        }
    }
    if (tmp < 2) cout << "-1";
    else {
        bool first_aux = true, second_aux = true;
        for (int i=0; i<n; i++) {
            if (a[i] == first || a[i] == second){
                if (a[i] == first && first_aux) {
                    a[i] = 1;
                    first_aux = false;
                }
                else if (a[i] == first && !first_aux) a[i] = 2;
                else if (a[i] == second && second_aux) {
                    a[i] = 1;
                    second_aux = false;
                }
                else if (a[i] == second && !second_aux) a[i] = 3;
            } else a[i] = 1;
            cout << a[i] << " ";
        }
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) solve();
    return 0;
}  
