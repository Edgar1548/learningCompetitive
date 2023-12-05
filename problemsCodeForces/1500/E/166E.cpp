#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll modl = 1e9+7;
void solve(int n){
    ll total = 0;
    if (n == 0) total = 1;
    else for (int i=1; i<n; i++){
        total = (total * 3) % modl;
        if (i & 1){
            total++;
        } else total--;
    }
    total = (total * 3)%modl;
    cout << total << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n);
    return 0;
} 		 	 	  	  				