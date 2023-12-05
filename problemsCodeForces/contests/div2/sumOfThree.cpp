#include <bits/stdc++.h>
using namespace std;



void solve(){
    int n; cin >> n;
    unordered_map<int, int> visits;
    for (int i=n-1; i>=0; i--){
        visits[1] = true;
        if ((n-1)%2==0){
            if (n-1 != i && i%3 != 0 && i%2 == 0){
                if (visits.find(i) != visits.end() || visits.find(n-1 - i) != visits.end()) break;
                visits[i] = true;
                if (visits.find(n-1 - i) != visits.end()) break;
                visits[n-1-i] = true;
                //cout << 1 << " " << i << " " << n-1 - i << "\n";
                break;
            }
        }
        else {
            if (n-1 != i && i%3 != 0 && i%2 != 0){
                if (visits.find(i) != visits.end() || visits.find(n-1 - i) != visits.end()) break;
                visits[i] = true;
                if (visits.find(n-1 - i) != visits.end()) break;
                visits[n-1-i] = true;
                //cout << 1 << " " << i << " " << n-1 - i << "\n";
                break;
            }
        }
    }
    if (visits.size() == 3){
        cout << "YES\n";
        for (auto it: visits){
            cout << it.first << " ";
        }
        cout << "\n";
    } else cout << "NO\n";
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
