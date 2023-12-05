#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, k, a, steps, countTwo = 0, countOnes = 0;
    cin >> n >> k;
    int lest = 100;
    for (int i=0; i<n; i++){
        cin >> a;
        if (a == 2 || a%2 == 0) countTwo++;
        if (a == 1 || a%2 != 0) countOnes++;
        if (a % k == 0) steps = 0;
        else {
            int tempA = a;
            a = (a/k + 1)*k;
            steps = abs(tempA-a);
        }
        lest = min(lest, steps); 
    }
    if (k == 4){
        if (countTwo > 1) lest = 0;
        else if (countTwo == 1 && countOnes >= 1) lest = min(lest, 1);
        else if (countOnes >= 1)  lest = min(lest, 2);  
    }
    cout << lest << "\n";
}   
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        solve();
    }
    return 0;
}