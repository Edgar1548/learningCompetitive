#include <bits/stdc++.h>
using namespace std;

void solve(int n){
    priority_queue<int> pq;
    queue<int> qu;
    stack<int> st;
    int x;
    int type;
    int possible[3] = {0};
    for (int i=0; i<n; i++){
        cin >> type;
        cin >> x;
        if (type == 1){
            if (possible[0] != -1) pq.push(x);  
            if (possible[1] != -1) qu.push(x);
            if (possible[2] != -1) st.push(x);
        }
        else{
            if (possible[0] == 0){
                if (pq.empty() || (pq.top() != x)){
                    possible[0] = -1;
                } else {
                    pq.pop();
                }
            }
            if (possible[1] == 0){
                if (qu.empty() || (qu.front() != x)){
                    possible[1] = -1;
                } else {
                    qu.pop();
                }
            }
            if (possible[2] == 0){
                if (st.empty() || (st.top() != x)){
                    possible[2] = -1;
                } else {
                    st.pop();
                }
            }
        }
    }
    if ((possible[0] == -1) && (possible[1] == -1) && (possible[2] == -1)){
        cout << "impossible";
    } else if ((0 == possible[0] && 0 == possible[1]) || (0 == possible[1] && 0 == possible[2]) || (0 == possible[0] && 0 == possible[2]))
        cout << "not sure"; 
    else{
        if (0 == possible[0]){
            cout << "priority queue";
        } else if (0 == possible[1]){
            cout << "queue";
        } else { 
            cout << "stack";
        }
    }
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n = 0;

    while(cin >> n){
        solve(n);
    }
    return 0;
}      