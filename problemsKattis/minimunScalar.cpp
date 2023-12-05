#include <bits/stdc++.h>
using namespace std;

//Solve basicamente recorre ambos multiset(vienen ordenados) de tamaño n y 
//tomando en cuenta que la eleccion greedy tomada fue multiplicar 
//el maximo de un array con el minimo del otro, toma el inicio de un array el final de otro con iteradores
// y suma las multiplicaciones de cada par y las gaurda en accum para luego imprimir
// Es facil ver que la complejidad de solve es O(n) 
void solve(int n, int t, vector<multiset<long long>> vc){
    auto start = vc[0].begin();
    auto end = vc[1].end();
    end--;
    long long accum = 0;
    for(int i=0; i<n; i++){
        accum += (*start) * (*end);
        start++;
        end--;
    }
    cout << "Case #"<< t+1 << ": " << accum << "\n";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=0; int n;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        //Mas destacado es que para guardar los valores del array se usa un vector con dos multiset para poder guardar
        //los valores ordenados (se usa multiset por que es posible que puedan venir repetidos)
        vector<multiset<long long>> vc;
        multiset<long long> ms;
        multiset<long long> ms2;
        //Cada insert tiene una complejidad de O(logn), y ya que se hace n cin 2 veces, en general la complejidad para guardar
        //los elementos seria de O(nlogn)
        for (int k=0; k<n; k++){
                int temp;
                cin >> temp;
                ms.insert(temp); 
        }
        for (int k=0; k<n; k++){
                int temp;
                cin >> temp;
                ms2.insert(temp); 
        }
        vc.push_back(ms);
        vc.push_back(ms2);
        //La complejidad general para resolver cada test seria O(n+nlogn) ~ O(nlogn) 
        solve(n, i, vc);
    }
    return 0;
}     