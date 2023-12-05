// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
 
void solve(int n, vector<int> vc, unordered_map<int, int> pos)
{
    sort(vc.begin(), vc.end());
    cout << pos[vc[n-1]] << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; int n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {   
        cin >> n;
        vector<int> toSolve(n);
        unordered_map<int, int> positions;
        for (int j = 0; j < n; j++){
            cin >> toSolve[j];
            positions[toSolve[j]] = j+1; 
        }
        solve(n, toSolve, positions);
    }
 
    return 0;
}