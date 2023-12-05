#include <bits/stdc++.h>
using namespace std;
#define ll long long
unordered_map<int, int> mpStatus;
map<int, map<int, int>> mpCnt;
unordered_map<int, int> positions;
void solve(int n){
    int m = 0, minCost = 0;
    vector<vector<int>> mt(30001, vector<int>(n, 0));
    vector<int> arr(n);
    for (int i=0; i<n; i++){
        map<int, int> temp;
        cin >> arr[i];
        if (mpStatus.find(arr[i]) != mpStatus.end()) mpStatus[arr[i]] = 2;
        else mpStatus[arr[i]] = 1; 
        temp[arr[i]] = 1;
        mpCnt[arr[i]] = temp;
        positions[arr[i]] = i+1;
    }
    sort(arr.begin(), arr.end());
    for (int i=0; i<=30000; i++){
        if (mpStatus.find(i) == mpStatus.end()) mpStatus[i] = 0;
        for (int j=0; j<n; j++){
            if (i >= arr[j]) mt[i][j] = i-arr[j];
            else break;
            if (mpStatus[mt[i][j]] != 0){
                if (mpStatus[mt[i][j]] == 2) {
                    mpStatus[i] = 2;
                    break;
                }
                auto cntTemp = mpCnt[mt[i][j]];
                if (cntTemp.find(arr[j]) != cntTemp.end()) cntTemp[arr[j]]++;
                else cntTemp[arr[j]] = 1;

                if (mpCnt[i].size() == 0)
                    mpCnt[i] = cntTemp;
                else{
                    if (mpCnt[i] != cntTemp){
                        mpStatus[i] = 2;
                        break;
                    }
                }
                mpStatus[i] = 1;
            }
        }
    }

    cin >> m;
    for (int i=0; i<m; i++){
        int temp; 
        cin >> temp;
        if (mpStatus[temp] == 0) cout << "Impossible";
        else if (mpStatus[temp] == 2) cout << "Ambiguous";
        else {
            multiset<int> mset;
            for (auto it: mpCnt[temp]){
                for (int i=0; i<it.second; i++){
                    mset.insert(positions[it.first]);
                }
            }
            for (auto it: mset){
                cout << (int)it << " ";
            }
        }
        cout << "\n";
    } 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n);
    return 0;
}
