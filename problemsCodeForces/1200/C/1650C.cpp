// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Point{
    int coord;
    int wgt;
};
bool cmpCoord(Point &a, Point &b){
    return a.coord < b.coord;
}
bool cmpCoordWgt(Point &a, Point &b){
    if (a.wgt == b.wgt) return a.coord < b.coord;
    return a.wgt < b.wgt;
}

vector<Point> points;
unordered_map<int, int> mapPoint;
void solve()
{
    int n, m;
    ll res = 0;
    cin >> n >> m;
    points.resize(m+1);
    for (int i=1; i<=m; i++){
        Point p;
        cin >> p.coord >> p.wgt;
        points[i] = p;
        mapPoint[p.coord] = i;
    }
    sort(points.begin()+1, points.end(), cmpCoordWgt);
    sort(points.begin()+1, points.begin()+2*n+1, cmpCoord);
    for (int i=1; i<2*n+1; i++){
        res += points[i].wgt;
    }
    cout << res << "\n";
    for(int i=1; i<=n; i++){
        cout << mapPoint[points[i].coord] << " " << mapPoint[points[2*n-i+1].coord] << "\n";
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {   
        solve();
    }
 
    return 0;
}