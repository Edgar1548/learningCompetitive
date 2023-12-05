#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
void solve(){
    int t;
    int Bx, By;
    int aux;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> Bx; cin >> By;
        int mid = (Bx + By)/2;
        for (int Cx = 0; Cx<Bx + mid+1; Cx++){
            for (int Cy = 0; Cy<By + mid +1; Cy++){
                if (Cx + Cy == mid && abs(Cx-Bx) + abs(Cy-By) == mid){
                    aux = 1;
                    cout << Cx << " " << Cy << endl;
                    break;
                }
            }    
            if (aux == 1){
                break;
            }        
        }
        if (aux == 0){
            cout << -1 << " " << -1 << endl;
        }
        aux = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}