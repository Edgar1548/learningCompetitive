#include <bits/stdc++.h>
using namespace std;
int n = 8; // Cantidad de rows y cols (tablero 8x8)

//Solve es una funcion recursiva que al ubicar una reina en una posicion, que antes de avanzar al siguiente row, marca como no posibles
//posiciones a la columna donde ubicaste a la reina anterior, y sus diagonales, asimismo si es que la posicion ha sido
//marcada como reservada, tampoco sera posible ubicar una reina. Si es que se llega a ubicar 8 reinas, se sumara contador que cuenta
//las formas de ubicar las reinas, se retrocede un paso y se comenzara a retroceder para checkear las columnas y volver a intentar 
//ubicar 8 reinas
void solve(int y, int &contador, bool col[], bool diag1[], bool diag2[], vector<vector<bool>> pos){
    if (y == 8){
        contador++;
        return;
    }
    for(int i=0; i<n; i++){
        if (col[i] || diag1[i+y] || diag2[i-y+n-1] || pos[y][i]){
            
            continue;
        }
        col[i] = true; diag1[i+y] = true; diag2[i-y+n-1] = true;
        solve(y+1, contador, col, diag1, diag2, pos);
        col[i] = false; diag1[i+y] = false; diag2[i-y+n-1] = false; 
    }
}

//Destacable que creamos un vector de vectores para guardar las posiciones de row, col donde se marcan las posiciones reservadas
//Asimismo se crean los arrays de col, y de las posibles diagonales
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char elem; int contador=0;
    vector<vector<bool>> vc(n, vector<bool>(n));
    bool col[n] = {false}; bool diag1[2*(n-1)+1] = {false}; bool diag2[2*(n-1)+1] = {false}; 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> elem;
            if (elem == '*'){
                vc[i][j] = true;
            }   
        }
    }
    solve(0, contador, col, diag1, diag2, vc);
    cout << contador << "\n";
    return 0;
}   