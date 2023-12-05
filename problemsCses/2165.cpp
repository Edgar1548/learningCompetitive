#include <bits/stdc++.h>
using namespace std;

void hanoi(int k, int from, int to, vector<pair<int, int>> &result){
    if (k == 1){
        result.push_back({from, to});
        return;
    }
    int idk = 6-(from+to);
    hanoi(k-1, from, idk, result);
    result.push_back({from, to});
    hanoi(k-1, idk, to, result);
}

void solve(int k){
    vector<pair<int, int>> result; 
    hanoi(k, 1, 3, result);
    int size = result.size();
    cout << size << "\n";
    for (int i=0; i<size; i++){
        cout << result[i].first << " " << result[i].second << " \n"[i+1<size];
    }
}

int main(){
    int k;
    int result = 0;
    cin >> k;
    solve(k);
    return 0;
}     