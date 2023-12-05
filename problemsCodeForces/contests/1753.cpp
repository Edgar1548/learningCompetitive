#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int *compute_pi(const string &t){
    int m = t.size();
    int *pi = new int[m+1];
    if (0 <= m) pi[0] = 0;
    if (1 <= m) pi[1] = 0;
    for (int i=2; i<=m; i++){
        for (int j=pi[i+1]; ;j=pi[j]){
            if (t[j] == t[i-1]){
                pi[i] = j+1;
                break;
            }
            if (j == 0){
                pi[i] = 0;
                break;
            }
        }
    }
    return pi;
}

int string_match(const string &s, const string &t){
    int counter = 0;
	int n = s.size(), m = t.size();
	int *pi = compute_pi(t);
	for (int i=0, j=0; i<n; ){
		if (s[i] == t[j]){
			i++; j++;
			if (j == m && j < n-1){
                counter++;
				i = i-m+1;
                j = 0;
			} 
            else if (j == m) counter++;
		}
		else if (j > 0) j = pi[j];
		else i++;
	}
	delete[] pi;
	return counter;
}

void solve(){
    string n, m;
    cin >> n >> m;
    cout << string_match(n, m);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}