#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(string str){
    int size = str.size(), totalU = 0, totalL =  0;
    vector<pair<int, int>> weirdVC;
    for (int i = 0; i<size; i++){
        if (isupper(str[i])) {
            totalU++;            
            if (!isupper(str[i+1]) || i == size-1) {
                weirdVC.push_back({totalL, totalU});
            }
        } else{
            if (i == 0 || isupper(str[i-1])) weirdVC.push_back({totalL, totalU});
            totalL++;
        }
    }
    int mini = size;
    if (weirdVC.size() == 0){
        mini = 0;
    } else {
        for (int i = 0; i< weirdVC.size(); i++){
            mini = min(mini, weirdVC[i].first + (totalU - weirdVC[i].second)); 
        }
    }
    cout << mini;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;
    solve(str);
    return 0;
}      