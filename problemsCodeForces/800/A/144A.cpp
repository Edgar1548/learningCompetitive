#include <bits/stdc++.h>
using namespace std;
void solve(int n){
    int arr[n], counter = 0, min = -1, max = -1;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        if (min == -1 || arr[i] < arr[min] || arr[min] == arr[i]) min = i;
        if (max == -1 || arr[i] > arr[max]) max = i;
    }
    int distanceMin = n-1 - min;
    int distanceMax = max;
    if (min < max) distanceMax--;    
    cout << distanceMin + distanceMax;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n);
    return 0;
}
