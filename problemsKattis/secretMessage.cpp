#include <bits/stdc++.h>
using namespace std;
void solve(){
    int N;
    string msg;
    int L;
    cin >> N;
    int counter = 0;
    for (int i=0; i<N; i++){
        cin >> msg;
        L = msg.size();
        int K = ceil(sqrt(L));
        vector<vector<char>> encrypted(K, vector<char>(K));
        for(int i=0; i<K; i++){
            for(int j=0; j<K; j++){
                if (counter >= L){
                    encrypted[j][i] = '*';
                } else {
                    encrypted[j][i] = msg[counter]; 
                    counter++;
                }
            }
        }
        for (auto i:encrypted){
            for (int j=K-1; j>=0; j--){
                if (i[j] != '*'){
                    cout << i[j];
                }
            }
        }
        cout << endl;
        counter = 0;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}     