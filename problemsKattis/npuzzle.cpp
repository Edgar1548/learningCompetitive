#include <bits/stdc++.h>
using namespace std;

int calculateDist(pair<int, int> originalPos, pair<int, int> pos){
    return abs(pos.first - originalPos.first) + abs(pos.second - originalPos.second);
}

void solve(int &result, char letter, int fil, int col, unordered_map<char, pair<int, int>> original){
    cin >> letter;
    int filOriginal = original[letter].first;
    int colOriginal = original[letter].second;
    if ((fil == filOriginal && col == colOriginal) || letter == '.') return;
    result += calculateDist(original[letter], {fil, col});
}

int main(){
    unordered_map<char, pair<int, int>> original;
    char start = 'A';
    char letter;
    int result = 0;
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (i == 3 && j == 3) start = '.';
            original[start] = {i,j};
            start++;
        }
    }
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            solve(result, letter, i, j, original);
        }
    }
    cout << result;
    return 0;
}      