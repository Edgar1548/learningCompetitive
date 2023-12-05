#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(multiset<int> ms, int n){
    int counter = 1;
    ll accum = 0;
    for (auto it = ms.rbegin(); it!=ms.rend(); it++){
        if (counter % 3 != 0) accum += (*it);
        counter++;
    }
    cout << accum << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    multiset<int> ms;
    int n; int m; 
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> m; 
        ms.insert(m);
    }
    solve(ms, n);
    return 0;
}      
