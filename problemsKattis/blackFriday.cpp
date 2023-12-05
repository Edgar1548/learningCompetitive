#include <bits/stdc++.h>
using namespace std;
void solve(){
    int C;
    int N;
    int weigth;
    vector<int> vc;
    int cantity = 0;
    int maxCantity = 0;
    cin >> N;
    cin >> C;
    for (int i=0; i<N; i++){
        cin >> weigth;
        vc.push_back(weigth);
    }
    int temp = C;
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            if (vc[j] <= C){
                cantity++;
                C -= vc[j]; 
                if (C == 0) break;
            }
        }
        if (maxCantity < cantity) maxCantity = cantity;
        C = temp;
        cantity = 0;
    }
    cout << maxCantity;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}