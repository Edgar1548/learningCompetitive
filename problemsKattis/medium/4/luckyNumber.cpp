#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll counter = 0;
int n;

bool checkDivisible(string numb, int k){

    
    
    return false;
}

void searchLucky(string numb, int k){
    bool divisible = checkDivisible(numb, k);
    if (!divisible) return;
    if (divisible && n == k){
        counter++;
    }   
    for (int i=0; i<10; i++){
        string tempNumber = numb + (char)i;
        searchLucky(tempNumber, k+1);
    }
}

void solve(){
    cin >> n;
    for (int i=1; i<10; i++){
        searchLucky(i, 1);
    }
    cout << counter << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}