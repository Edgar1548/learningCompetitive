#include <bits/stdc++.h>
using namespace std;
int binarySearch(int s, int left, int rigth, vector<int>& vc){
    if (left > rigth) return -1;
    int mid = (left+rigth)/2;
    if (vc[mid] == s) return mid;
    if (vc[mid] < s) return binarySearch(s, mid+1, rigth, vc);
    return binarySearch(s, left, mid-1, vc);
}

void solve(int n){
    vector<int> vc(n); int toSearch;
    for (int i=0; i<n; i++){
        cin >> vc[i];
    }
    cin >> toSearch;
    cout << binarySearch(toSearch, 0, n-1, vc) << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n);
    return 0;
}      
