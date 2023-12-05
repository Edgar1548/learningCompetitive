#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<char, int> positions;

void setPositions(){
    int i = 0;
    for (; i<9; i++){
        positions[(i+1)+'0'] = i;
    }
    positions['0'] = 9;
}

void solve(){
    string s;
    cin >> s;
    int pos = 0, posActual, distance, steps = 0;
    char initial = '1', actual;
    for (int i=0; i<4; i++){
        actual = s[i];
        posActual = pos;
        if (initial != actual) posActual = positions[actual];
        distance = abs(posActual - pos);
        steps += (distance + 1);
        pos = posActual;
        initial = actual;
    }
    cout << steps << "\n";
}   
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    setPositions();
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        solve();
    }
    return 0;
}