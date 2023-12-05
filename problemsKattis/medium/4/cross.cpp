#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define N 9
vector<unordered_map<char, bool>> mpCol(N);
vector<unordered_map<char, bool>> mpRow(N);
vector<unordered_map<char, bool>> squares(N);
char arr[N][N];  

bool checkSquares(){
    int posSquare = 0;
    for (int i=0; i<N; i+=3){
        for (int j=0; j<N; j+=3){
            for (int row=0; row<3; row++){
                for (int col=0; col<3; col++){
                    int x = j + col, y = i + row;
                    if (arr[y][x] != '.' && squares[posSquare].find(arr[y][x]) == squares[posSquare].end()){
                        squares[posSquare][arr[y][x]] = true;
                    } else if ( arr[y][x] != '.') return false;
                }
            }
            posSquare++;
        }
    }
    return true;
}

pair<int, int> isPossible(char n, int i, int j, int posSquare){
    int possibles = 0; pair<int, int> ret;
    for (int row=0; row<3; row++){
        for (int col=0; col<3; col++){
            int x = j + col, y = i + row;
            if (arr[y][x] != '.') continue;
            if (mpRow[y].find(n) == mpRow[y].end() && mpCol[x].find(n) == mpCol[x].end()) {
                possibles++;
                ret = {x, y};
            } 
            if (possibles > 1) break;
        }
    }
    if (possibles == 1) return ret;
    if (possibles == 0) return {-2, -2};
    return {-1, -1};
}


bool addElements(){
    vector<char> chars = {'1','2','3','4','5','6','7','8','9'};
    bool thereIsActualization = true;
    int posSquare = 0;
    while (thereIsActualization) {
        thereIsActualization = false;
        posSquare = 0;
        for (int i=0; i<N; i+=3){
            for (int j=0; j<N; j+=3){
                for (auto it: chars){
                    if (squares[posSquare].find(it) != squares[posSquare].end()) continue;
                    auto pXY = isPossible(it, i, j, posSquare);
                    if (pXY.first == -1) continue;
                    if (pXY.first == -2) {
                        return false;
                    }
                    arr[pXY.second][pXY.first] = it;
                    squares[posSquare][it] = true;
                    mpRow[pXY.second][it] = true;
                    mpCol[pXY.first][it] = true;
                    thereIsActualization = true;
                }
                posSquare++;
            }
        }
    }
    return true;
}

void solve(){
    char dot;
    bool check = true;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> dot;
            arr[i][j] = dot;
            if (dot != '.' && (mpRow[i].find(dot) == mpRow[i].end() && mpCol[j].find(dot) == mpCol[j].end())){
                mpRow[i][dot] = true;
                mpCol[j][dot] = true;
            } else if ( dot != '.') check = false;
        } 
    }
    if (check && checkSquares() && addElements()){
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                cout << arr[i][j];
            } 
            cout << "\n";
        }

    } else cout << "ERROR";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}