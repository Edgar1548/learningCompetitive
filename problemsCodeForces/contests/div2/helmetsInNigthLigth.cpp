#include <bits/stdc++.h>
typedef long long ll;
struct Resident{
    int costToAnnounce, shareCapacity;
};

bool compare(Resident a, Resident b){
    if (a.costToAnnounce == b.costToAnnounce){
        return a.shareCapacity > b.shareCapacity;
    } 
    return a.costToAnnounce < b.costToAnnounce;
}

using namespace std;
void solve(int t){
    int n, p; cin >> n >> p;
    Resident arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i].shareCapacity;
    }
    for (int i=0; i<n; i++){
        cin >> arr[i].costToAnnounce;
    }
    sort(arr, arr+n, compare);
    ll cost = p, pos = 0, left = n-1;
    while(left > 0){
        if (p > arr[pos].costToAnnounce){
            cost += arr[pos].costToAnnounce * ( left > arr[pos].shareCapacity ? arr[pos].shareCapacity : left);
            left -= arr[pos].shareCapacity;
        } else {
            cost += left * p;
            left = 0;
        }
        pos++;
    }

    cout << cost << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    for (int i=0; i<t; i++){
        solve(t);
    }
    return 0;
}
