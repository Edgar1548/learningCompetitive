#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long A, B;
    unordered_map<long long, long long> counts;
    while (true){
        cin >> A; cin >> B;
        if (A == 0 && B == 0) break;
        bool check = true;
        long long tempA = A; long long tempB = B;
        long long countA = 0; long long countB = 0;
        counts[A] = countA;
        while(true){
            if (A == B){
                cout << tempA << " needs " << countA << " steps, " << B << " needs " << countB << " steps, they meet at " << A << "\n"; 
                check = false;
                break;
            }
            if (A == 1) break;
            if (A & 1 == 1){
                A = 3 * A + 1;
            } else A = A * 0.5;
            countA++;
            counts[A] = countA;
        }
        while(check == true){
            if (counts.find(B) != counts.end()){
                cout << tempA << " needs " << counts[B] << " steps, " << tempB << " needs " << countB << " steps, they meet at " << B << "\n";
                break;
            }
            if (B == 1) break;
            if (B & 1 == 1){
                B = 3 * B + 1;
            } else B = B * 0.5;
            countB++;
        }
        counts.clear();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}      