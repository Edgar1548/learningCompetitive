#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string to;
    string from;
    string read;
    unordered_map<string, string> dic;
    getline(cin, read);
    while (read != ""){
        stringstream s(read);
        s >> to;
        s >> from;
        dic[from] = to;
        getline(cin, read);
    }
    while(cin >> read){
        if (dic.find(read) == dic.end()){
            cout << "eh";
        } else cout << dic[read];
        cout << "\n";
    }
    
    return 0;
}      