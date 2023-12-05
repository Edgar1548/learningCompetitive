#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> parent;
vector<int> sizes;

int Find(int x){
    while(parent[x] != x){
        x = parent[x];
    }
    return x;
}

void Union(int x, int y, int &maxSize){
    if (sizes[x] < sizes[y]) {
        parent[x] = y;
        sizes[y] += sizes[x];
    }
    else {
        parent[y] = x;
        sizes[x] += sizes[y];
    }
    if (max(sizes[x], sizes[y]) > maxSize) maxSize = max(sizes[x], sizes[y]);
}


void solve(){
    int n, m, a, b, w;
    cin >> n >> m;
    parent.resize(n+1);
    iota(parent.begin()+1, parent.end(), 1);
    sizes.resize(n+1, 1);
    int counterComponents = n, maxRank = 1;
    for (int i=0; i<m; i++){
        cin >> a >> b;
        int pU = Find(a), pV = Find(b);
        if (pU != pV){
            counterComponents -= 1;
            Union(pU, pV, maxRank);
        }
        cout << counterComponents << " " << maxRank << "\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}