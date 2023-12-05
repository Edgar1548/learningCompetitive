#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int findMinMax(int k){
    int x, minCord = -1, maxCord = -1;
    for (int j=0; j<k; j++){
        cin >> x;
        if (minCord > x || minCord == -1) minCord = x;
        if (maxCord < x || maxCord == -1) maxCord = x;
    }
    return (maxCord-minCord);
}

void solve(){
    int w, h, k, x, dist;
    ll maxDistanceH = 0, maxDistanceV = 0, maxDist;
    cin >> w >> h;
    for (int i=0; i<2; i++){ 
        cin >> k;
        dist = findMinMax(k);
        if (dist > maxDistanceH) maxDistanceH = dist;
    }
    for (int i=0; i<2; i++){
        cin >> k;
        dist = findMinMax(k);
        if (dist > maxDistanceV) maxDistanceV = dist;
    }
    maxDist = max(maxDistanceV*w, maxDistanceH*h);
    cout << maxDist << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        solve();
    }
    return 0;
}