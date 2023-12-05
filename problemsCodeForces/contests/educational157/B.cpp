#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[100];
void solve() {
    int n;
    int minPath = 0;
    cin >> n;
    pair<int, int> point = {-1, -1};
    for (int i=0; i<2*n; i++) cin >> arr[i];
    sort(arr, arr+2*n);
    int start = 0, end = 2*n-1;
    while(start < end){
        if (point.first == -1) point = {arr[start], arr[end]};
        else {
            minPath += (abs(point.first - arr[start]) + abs(point.second - arr[end]));
            
            point = {arr[start], arr[end]};
        }
        start++;
        end--;
    }
    cout << minPath << "\n";
    start = 0; end = 2*n-1;
    while(start < end){
        cout << arr[start] << " " << arr[end] << "\n";
        start++;
        end--;
    }
    
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