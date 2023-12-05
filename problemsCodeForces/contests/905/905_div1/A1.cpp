#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct ab{
    ll a, b;
    int s;
};
bool comp(ab &u, ab &v){
    if (u.b == v.b) return v.a < u.a;
    return v.b < u.b;
}
int iterations = 0;
vector<ab> vcAB;
int fo(int i, int j, map<int, bool> &markedList, int score){
    if (iterations <= 200) cout << j << "\n";
    iterations++;
    if (i == n) return score;
    if (vcAB[i].a >= vcAB[j].b && !markedList[vcAB[j].s]){
        int res = 1e6;
        for (int x = j; x < n; x++){
            if (markedList[vcAB[x].s]) continue;
            markedList[vcAB[x].s] = true;
            res = min(fo(i+1, j, markedList, score+1), res);
            markedList[vcAB[x].s] = false;    
        }
        score = res;
    }   
    else if (markedList[vcAB[j].s]) score = fo(i, j+1, markedList, score); 
    else score = fo(i+1, j+1, markedList, score); 
    return score;
}

void solve() {
    int m;
    ll ai, bi;
    cin >> n >> m;
    vcAB.resize(n);
    map<int, bool> markedList;
    vcAB[0].a = 1;
    for (int i=1; i<n; i++){
        cin >> vcAB[i].a;
    }
    for (int i=0; i<n; i++){
        cin >> vcAB[i].b;
        vcAB[i].s = i;
        markedList[i] = false;
    }
    sort(vcAB.begin(), vcAB.end(), comp);
    sort(vcAB.begin(), vcAB.end(), comp);
    auto score = fo(0, 0, markedList, 0);
    cout << score << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        solve();
    }    
    return 0;
}