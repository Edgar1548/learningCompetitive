#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> W;
vector<int> X;

bool aceptableDifference(int x, int i, int j){
    if (x + i >= 24){
        i = x + i -24;
    } else i = x+i;
    if (x + j >= 24){
        j = x + j -24; 
    } else j = x+j;
    if (i >=9 && i<=18 && j >=9 &&j <= 18) return true;
    return false;
}

void solve(){
    int N, res = 0;   
    cin >> N;
    W.resize(N);
    X.resize(N);
    for (int i=0; i<N; i++){
        cin >> W[i] >> X[i];
    }
    for (int i=0; i<24; i++){
        for (int j=i; j<24; j++){
            int tempRes = 0;
            for (int k=0; k<N && i!=j; k++){
                if (aceptableDifference(X[k], i, j)){
                    tempRes+=W[k];
                }
            }
            res = max(res, tempRes);
        }
    }
    cout << res << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}