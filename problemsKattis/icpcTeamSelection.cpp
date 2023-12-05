#include <bits/stdc++.h>
using namespace std;

//La eleccion greedy de este problema fue tomar el mayor posible con los dos menores posibles para cada equipo de 3
//Entonces tomando como iteradores el principio y el final del multiset, se va avanzando y sumando los segundos menores valores
//(Ya que vendrian a ser el valor del medio de cada grupo) -> 1(menor) 2(segundo menor-mediana) 3(mayor)
void solve(int n, multiset<int> ms){
    auto start = ms.begin();
    auto end = ms.end();
    end--;
    double accum = 0;
    for (int i=0; i<n; i++){
        end--;
        accum += (*end);
        start++;
        end--;
    }
    cout << accum << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    int n;
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> n;
        //Se usa un multiset para tener un array ordenado
        //La complejidad del insert en multiset es O(logn)
        multiset<int> numbers;
        for (int j=0; j<3*n; j++){
            int temp;
            cin >> temp;
            numbers.insert(temp);
        }
        //Entonces ya que se usa for de n(O(n)) en solve y para insertar todos los datos en numbers se usa un insert dentro del for
        //La complejidad seria O(nlogn) para cada test case
        solve(n, numbers);
    }

    return 0;
}      