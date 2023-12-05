#include <bits/stdc++.h>
using namespace std;

//calculate se encarga de calcular cuantos 5 y 3 se deben imprimir, 
//caso devuelvan -1 y -1, es por que no se puede conseguir el Decent Number
//La eleccion greedy para este caso es colocar tantos 5 como sean posibles mientras el resto de la cantidad de digitos posibles
//sea disivible por 5 en caso la cantidad de digitos no sea una division exacta de 3
pair<int, int> calculate(int n, int limit){
    //Se itera sobre la cantidad de 5 posibles que se puedan colocar
    //en este caso i primero empieza como el maximo posibles de 5 que se pueden colocar, y llega a 0, donde no se debe colocar ningun 5
    for (int i=limit; i>=0; i--){
        int res = n-i*3;
        //en caso el rest sea 0, significa que el numero es divisible por 3, por lo que se debe imprimir n veces 5
        if (res == 0) return {n, 0};
        else if (res%5 == 0) return {3*i, res};
        //caso contrario, si el resto es disivible por 5, se debe imprimir el resto de veces 3 despues de los 5
    }
    return {-1,-1};
}

void solve(int n){
    //divimos n entre 3 y el piso del resultado sera la cantidad maxima de veces que se puede imprimir 5 luego de multiplicar por 3
    int limit = floor(n/3);
    //el first del pair sera la cantidad de 5s a imprimir y second guardara la cantidad de 3s
    pair<int, int> cant = calculate(n, limit);
    //en caso se haya devuelto -1 para el pair se imprime -1
    if (cant.first == -1 && cant.second == -1){
        cout << -1;
    } else {
        //caso contrario se imprime los 5s y 3s
        for (int i=0; i<cant.first; i++){
            cout << 5;
        }
        for (int i=0; i<cant.second; i++){
            cout << 3;
        }
    }
    cout << "\n";
}

//La complejidad del calculate es O(n/3), y en el peor caso se hara un cout n veces en total, ya que si o si la cantidad
// de 5s y 3s tienen que sumar n, entonces, es O(n/3 + n), 
//Entonces O(n) es la complejidad para cada test
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    int n;
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> n;
        solve(n);
    }

    return 0;
}      