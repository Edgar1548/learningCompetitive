#include <bits/stdc++.h>
using namespace std;

int maxOper(int a, int b, int k){
    if (a == -1) return b;
    if (b == -1) return a;
    return min(abs(a-k), abs(b-k)) == abs(a-k) ? a : b ;
}

bool isValid(int k, unordered_map<int, pair<int, int>> coord){
    vector<int> arr;
    int r;
    while (k != 0) {
        r = k % 10;
        arr.push_back(r);
        k = k / 10;
    }
    for (int j = arr.size() - 1; j > 0; j--) {
        if(coord[arr[j]].first > coord[arr[j-1]].first || coord[arr[j]].second > coord[arr[j-1]].second) return false;
    }
    return true;
}
int valdez(int k, int originK, unordered_map<int, bool> isInvalid, unordered_map<int, pair<int, int>> coord){
    if (k < 0) return -1;
    //Una vez se llege a la 4ta carta se devuelve el acumulado
    if (isInvalid.find(k) == isInvalid.end()){
        if (isValid(k, coord) == false) {
            isInvalid[k] = true;
            int down = valdez(k-1, originK, isInvalid, coord);
            int up = valdez(k+1, originK, isInvalid, coord);
            return maxOper(down, up, originK);}
        else {
            isInvalid[k] = false;
            return k;
        }

    } 
    else if (!isInvalid[k]) return k;
    else return -1;
}

void solve(int k){
    unordered_map<int, bool> umap;
    unordered_map<int, pair<int, int>> coord;
    int num = 0;
    coord[num] = {3,1};
    for (int x=0; x<3; x++){
        for (int y=0; y<3; y++){
            num++;
            coord[num] = {x,y};
        }
    }
    int result = valdez(k, k, umap, coord);
    cout << result << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, k;
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> k; 
        solve(k); 
    }
    return 0;
}      