#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string tstr;
bool verify(string &s){
    int coincidences = 0;
    if (s.size() == tstr.size()){
        if (tstr == s) return true;
        else {
            for (int i=0; i<tstr.size(); i++){
                if (s[i] == tstr[i]) coincidences++;
                if (coincidences < i) return false;
            } 
            return true;
        }
    } else if (tstr.size()+1 == s.size()){
        bool isPossibleJump = true;
        int j = 0;
        for (int i=0; i<tstr.size(); i++){
            if (s[j] != tstr[i] && isPossibleJump) {
                isPossibleJump = false;
                j++;
            } 
            if (s[j] != tstr[i] && !isPossibleJump) return false;
            j++;
        } 
        return true;

    } else if (tstr.size()-1 == s.size()){
        bool isPossibleJump = true;
        int j = 0;
        for (int i=0; i<tstr.size(); i++){
            if (s[j] != tstr[i] && isPossibleJump) {
                isPossibleJump = false;
                i++;
            } 
            if (s[j] != tstr[i] && !isPossibleJump) return false;
            j++;
        }   
        return true;
    }
    return false;
}

void solve(){
    int N;
    string S;
    vector<int> goodStrs;
    cin >> N >> tstr;
    for (int i=0; i<N; i++){
        cin >> S;
        if (verify(S)) goodStrs.push_back(i+1);
    }
    if (goodStrs.empty()){
        cout << 0;
    } else {
        cout << goodStrs.size() << "\n";
        for (auto it:goodStrs){
            cout << it << " ";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}