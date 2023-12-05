#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segment{
    ll start, end;
};
bool compStart(segment a, segment b){
    if (a.start == b.start) return a.end < b.end;
    return a.start < b.start;
}
void solve(){
    int N, res; 
    ll t, d; 
    cin >> N;
    vector<segment> startVc;
    for (int i=0; i<N; i++){
        segment s;
        cin >> t >> d;
        s.start = t; s.end = t+d;
        startVc.push_back(s);
    }
    sort(startVc.begin(), startVc.end(), compStart);
    int i = 0, cnt = 0;
    ll time = 1;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    while(i < N ||  !pq.empty()){
        if (pq.empty() && i < N && startVc[i].start > time) time = startVc[i].start;
        while(i < N && startVc[i].start <= time) {
            pq.push(startVc[i].end);
            i++;
        }
        if(!pq.empty() && pq.top() >= time){
            cnt++;
            pq.pop();
            time++;
        }
        while(!pq.empty() && pq.top() < time) pq.pop();;
    }
    cout << cnt << "\n";
}   
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}