#include <bits/stdc++.h>
using namespace std;
void solve(int n){
    
    while(true){
        map<int, bool> mp;
        int temp = n;
        bool isDistinct = true;
        while (n > 0){
            int lastDigit = n%10;
            if (mp.find(lastDigit) != mp.end()) {
                isDistinct = false;
                break; 
            }
            mp[lastDigit] = true;
            n -= lastDigit;
            n /= 10;
        }
        mp.clear();
        n = temp;
        if (isDistinct) break;
        n++;
    }
    cout << n << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n+1);
    return 0;
}
