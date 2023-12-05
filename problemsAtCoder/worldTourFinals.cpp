#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> mp;
unordered_map<int, vector<int>> mpV;
void solve(){
    int n, m, maxP=0;
    cin >> n >> m;
    int costs[m];
    for (int i=0; i<m; i++){
        cin >> costs[i];
    }
    string str;
    for (int i=0; i<n; i++){
        vector<int> temp;
        mp[i] = 0;
        mpV[i] = temp;
        cin >> str; 
        for (int j=0; j<m; j++){
            if (str[j] == 'o'){
                mp[i] += costs[j];
            } else mpV[i].push_back(costs[j]);
        }
        mp[i] += i;
        if (maxP < mp[i]) maxP = mp[i];
    }
    
    for (int i=0; i<n; i++){
        int counter = 0;
        if (maxP != mp[i]) {
            auto tempVc = mpV[i];
            sort(tempVc.begin(), tempVc.end(), greater<>());
            int temp = mp[i];
            while (temp < maxP){
                temp += tempVc[counter];
                counter++;
            }
        }
        cout << counter << " \n"[i+1<n];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
