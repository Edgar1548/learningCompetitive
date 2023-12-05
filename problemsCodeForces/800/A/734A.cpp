#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(ll n){
    int countA = 0, countD = 0;
    char temp;
    for (int i=0; i<n; i++){
        cin >> temp;
        if (temp == 'A') countA++;
        else countD++; 
    }
    if (countA > countD) cout << "Anton";
    else if (countA < countD )cout << "Danik";
    else cout << "Friendship";
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    solve(n);
    return 0;
}