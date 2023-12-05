#include <bits/stdc++.h>
using namespace std;
int maxLimit = 2e5+1;
vector<vector<int>> vcs(maxLimit+1, vector<int>(18, 0));
void solve(int min, int max){
    vector<int> vcMin = vcs[min - 1 < 1 ? 1: min - 1];
    vector<int> vcMax = vcs[max];
    int maxRepeated = 0;
    for (int i=0; i<18; i++){
        if (maxRepeated < vcMax[i] - (min == 1 ? 0 : vcMin[i])){
            maxRepeated = vcMax[i] - (min == 1 ? 0 : vcMin[i]);
        }
    }   
    cout << (max - min) - maxRepeated + 1 << "\n";
}
void preCalculate(){
    vector<int> bits(18, 0);
    vcs[1][0] = 1;
    for (int i = 2; i <= maxLimit; i++){
        int temp = i;
        for (int j=0; j<18; j++){
            if ((temp & 1) == 1) vcs[i][j] = vcs[i-1][j]+1;
            else vcs[i][j] = vcs[i-1][j];
            temp = temp >> 1;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    preCalculate();
    int t; int min; int max;
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> min;
        cin >> max;
        solve(min, max);
    }
    return 0;
}      
