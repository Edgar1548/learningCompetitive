#include <bits/stdc++.h>
using namespace std;
void solve(){
    int N;
    int number;
    cin >> N;
    vector<int> arr;
    for(int i=0; i<N; i++){
        cin >> number;
        arr.push_back(number);
    }
    sort(arr.begin(), arr.end());
    int contador = 0;
    for (int i=0; i<N-1; i++){
        if (arr[i+1] != arr[i] + 1){
            if (contador > 1){
                cout << arr[i-contador] << "-" << arr[i]<< " " ;
            }
            else if (contador == 1){
                cout << arr[i-1] << " " << arr[i] << " ";
            }
            else {
                cout << arr[i] << " ";
            }
            contador = 0;
        }
        else contador++;
    }
    if (contador > 1){
        cout << arr[N-1-contador] << "-" << arr[N-1];
    }
    else if (contador == 1){
        cout << arr[N-2] << " " << arr[N-1];
    }
    else {
        cout << arr[N-1];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}