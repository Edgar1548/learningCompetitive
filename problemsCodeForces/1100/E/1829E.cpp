#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxL 1000
int sizes[maxL*maxL];
int parent[maxL*maxL];
int arr[maxL][maxL];

void Union(int parent_a, int parent_b){
    if (sizes[parent_a] < sizes[parent_b]) {
        sizes[parent_b] += sizes[parent_a];
        parent[parent_a] = parent_b;
    }
    else {
        sizes[parent_a] += sizes[parent_b];
        parent[parent_b] = parent_a;
    }
}

int Find(int k){
    if (parent[k] != k) {
        parent[k] = Find(parent[k]);
    }
    return parent[k];
}
void solve(){
    int n, m, maxLake = 0, parent_a, parent_b;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> arr[i][j];
            parent[i*m+j] = i*m+j;
            sizes[i*m+j] = arr[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            parent_a = Find(i * m + j);
            if (arr[i][j] > 0 && j + 1 < m && arr[i][j+1] > 0){
                int parent_c = Find(i * m + j + 1); 
                if (parent_a != parent_c) Union(parent_a, parent_c);
            }
            parent_a = Find(i * m + j);
            if (arr[i][j] > 0 && i + 1 < n && arr[i+1][j] > 0){
                parent_b = Find((i+1) * m + j);
                if (parent_a != parent_b) Union(parent_a, parent_b);
            }
            maxLake = max(maxLake, sizes[parent_a]);
        }
    }
    cout << maxLake << "\n";    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) solve();
    return 0;
}