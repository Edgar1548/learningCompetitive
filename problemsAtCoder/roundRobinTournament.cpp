#include <bits/stdc++.h>
using namespace std;
struct Result{
    int rank=0, wins=0, loses=0;
};
bool compare(Result r1, Result r2)
{   
    if (r1.wins == r2.wins) return (r1.rank < r2.rank);
    return (r1.wins > r2.wins);
}
void solve(){
    string str;
    int n; cin >> n;
    Result arr[n];
    for (int i=0; i<n; i++){
        arr[i].rank = i+1;
        cin >> str;
        for (int j=0; j<n; j++){
            if (str[j] == 'o') arr[i].wins++;
            else if (str[j] == 'x') arr[i].loses++;
        }
    }
    sort(arr, arr+n, compare);
    for (int i=0; i<n; i++){
        cout << arr[i].rank << " ";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
