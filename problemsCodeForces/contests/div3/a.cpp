#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, m; cin >> n >> m;
    string x, s; cin >> x >> s;
    int maxCoincidences = 0, numbOfMov = -1;
    numbOfMov = 0;
    while(n < m){
        x += x;
        n = x.size();
        numbOfMov++;
    }
    while(maxCoincidences < m){
        int tempMaxCoincidences = 0;
        for (int i=0; i<n; i++){
            int tempCoincidences = 0;
            if (x[i] == s[0]){
                tempCoincidences++;
                int tempI = i+1, tempJ = 1;
                while(tempI < n && tempJ < m && x[tempI] == s[tempJ]) {
                    tempCoincidences++;
                    tempI++;
                    tempJ++;
                }
            }
            tempMaxCoincidences = max(tempMaxCoincidences, tempCoincidences);
            if (tempMaxCoincidences == m) break;
        }
        if (tempMaxCoincidences <= maxCoincidences) {
            numbOfMov = -1;
            break;
        } else maxCoincidences = tempMaxCoincidences;
        if (maxCoincidences == m) break;
        x += x;
        n = x.size();
        numbOfMov++;
    }
    cout << numbOfMov << "\n";
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