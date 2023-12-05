#include <bits/stdc++.h>
using namespace std;
void solve(){
    int score = 0;
    int maxScore = 0;
    int participant = 1;
    int grade;
    for (int i=0; i<5; i++){
        for(int j=0; j<4; j++){
            cin >> grade;
            score += grade;
            if (maxScore < score){
                maxScore = score;
                participant = i+1;
            }
        }
        score = 0;
    }
    cout << participant << " " << maxScore;
}
int main(){

    solve();
    return 0;
}