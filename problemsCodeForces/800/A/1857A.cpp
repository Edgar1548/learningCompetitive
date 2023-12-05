#include <bits/stdc++.h>
using namespace std;
void solve(){
    int number;
    int size;
    int elem;
    int odds_count = 0;
    cin >> number;
    for (int i=0; i<number; i++){
        cin >> size;
        for (int j=0; j<size; j++){
            cin >> elem;
            if ((elem & 1) == 1){
                odds_count++;
            }
        }
        if ((odds_count & 1) == 1) cout << "NO" << endl;
        else cout << "YES" << endl;
        odds_count = 0;
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}