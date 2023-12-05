#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxL 200000
int parent[maxL+1];
int ranks[maxL+1];
void Union(int p_a, int p_b){
    if (p_a == 1 || p_b == 1){
        parent[p_a == 1? p_b:p_a] = 1;
        if (ranks[p_a] == ranks[p_b]){
            ranks[1]++;
        }
    } else {
        int r_a = ranks[p_a], r_b = ranks[p_b];
        parent[min(r_a, r_b)] = max(r_a, r_b);
        if (ranks[p_a] == ranks[p_b]){
            parent[p_b] = p_a;
            ranks[p_a]++;
        }
    }
}
int Find(int k){
    if(parent[k] != k){
        parent[k] = Find(parent[k]);
    }
    return parent[k];
}

void solve() {
    int n, m, a, b;
    cin >> n >> m;
    bool check = false;
    for (int i=0; i<n; i++) parent[i+1] = i+1;
    for (int i=0; i<m; i++){
        cin >> a >> b;
        int p_a = Find(a);
        int p_b = Find(b);
        if (p_a != p_b) Union(p_a, p_b);
    }
    int i = 0;
    for (; i<n; i++){
        int p_i = Find(i+1);
        if (p_i != 1) {
            check = true;
            cout << i+1 << "\n";
        }
    }
    if (!check) cout << "Connected\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}