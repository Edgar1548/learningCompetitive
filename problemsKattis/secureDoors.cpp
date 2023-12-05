#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n ;
    unordered_map<string, bool> inBuilding;
    cin >> n;
    string enEx;
    string name;
    for (int i=0; i<n;i++){
        cin >> enEx;
        cin >> name;
        if (enEx == "entry"){
            if (inBuilding.find(name) == inBuilding.end() || inBuilding[name] == false){
                inBuilding[name] = true;
                cout << name << " entered\n";
            } else {
                cout << name << " entered (ANOMALY)\n";
            }
        }
        else {
            if (inBuilding.find(name) == inBuilding.end() || inBuilding[name] == false){
                cout << name << " exited (ANOMALY)\n";
            } else {
                cout << name << " exited\n";
                inBuilding[name] = false;
            }
        }
    }
    return 0;
}      