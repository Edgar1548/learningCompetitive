#include <bits/stdc++.h>
using namespace std;
//Compara dos resultados, si uno 24 retorna 24 sin importar cual sea, en caso ninguno sea, si el mayor pasa 24 retorna el menor
int maxOper(int a, int b){
    if (a == 24 || b == 24) return 24;
    return max(a, b) < 24? max(a,b) : min(a,b);
}

//Se encarga de realizar todas las posibles operaciones de una permutacion de las cartas
int operate(int pos, int acum, vector<int> vc){
    //Una vez se llege a la 4ta carta se devuelve el acumulado
    if (pos == 4){
        return acum;
    }
    int value;
    //Llama a recursivamente dando diferente orden a las operaciones y comparando los resultados

    value = operate(pos + 1, acum + vc[pos], vc);
    value = maxOper(value, operate(pos + 1, acum * vc[pos], vc));
    value = maxOper(value, operate(pos + 1, acum - vc[pos], vc));
    if (acum % vc[pos] == 0){
        value = maxOper(value,operate(pos + 1 , acum / vc[pos], vc));
    }
    //Sirve para manejar el orden de los parentesis basicamente, cuando el pos 1, da un orden de (a?(b?c)?d) a las operaciones
    //Y para pos 2, da el orden de (a?b)?(c?d)
    if (pos < 3){
        //Es de notar que la operacion suma es innecesaria para el orden (a?(b?c))?d, ya que (a+(c*d))?d es igual a ((c*d)+a)?d, al cual se llegaria
        //en alguna permutacion de las cartas, pero es necesario para el pos 2, puesto que no hay equivalente de (a?b)+(c*d) 
        //Y asi como para la suma, algunas otras operaciones no son necesaria para pos 1 pero si para pos 2
        if (pos == 2){
            value = maxOper(value, operate(pos + 2, acum + (vc[pos]*vc[pos+1]), vc));
            value = maxOper(value, operate(pos + 2, acum * (vc[pos]+vc[pos+1]), vc));
            value = maxOper(value, operate(pos + 2, acum * (vc[pos]-vc[pos+1]), vc));
        }
        value = maxOper(value, operate(pos + 2, acum - (vc[pos]*vc[pos+1]), vc));
        //Antes de hacer div se verificar si es divisible
        if (vc[pos] % (vc[pos+1]) == 0){
            //No coloque el + en el pos == 2, debido a que deberia preguntar denuevo por la condicion y seria muy molestoso
            value = maxOper(value, operate(pos + 2, acum + (vc[pos]/vc[pos+1]), vc));
            value = maxOper(value, operate(pos + 2, acum - (vc[pos]/vc[pos+1]), vc));
        }
        if ( acum % (vc[pos]+vc[pos+1]) == 0) value = maxOper(value, operate(pos + 2,  acum / (vc[pos]+vc[pos+1]), vc));
        //Para este caso se debe verificar tambien que no sean iguales o que es lo mismo, que su resta no sea cero
        if ( vc[pos] != vc[pos+1] && acum % (vc[pos] - vc[pos+1]) ==0) {
            value = maxOper(value, operate(pos + 2,  acum / (vc[pos]-vc[pos+1]), vc));
        }
    }
    return value;
}

void solve(vector<vector<int>> vc, int n){
    for(int i=0; i<n; i++){
        auto vcTemp = vc[i];
        int maxTemp = 0;
        int temp = 0;
        //Se hace sort para que mantenga un orden lexicografico, es importante debido a que la funcion next_permutation, avanza lexicograficamente
        //las permutaciones, entonces en caso las cartas hayan estado en desorden, se perderan permutaciones
        sort(vcTemp.begin(), vcTemp.end());
        //Se itera sobre todas las posibles permutaciones y se actualiza maxTemp que tendra al valor mas alto <= 24
        do {
            int acum = vcTemp[0];
            int temp = operate(1, acum, vcTemp);
            //En caso se devuelva 24 se rompe el while y se imprime, caso contrario solo se actualiza el maxTemp de ser necesario
            if (temp == 24) {
                maxTemp = 24;
                break; 
            }
            else if (maxTemp < temp) maxTemp = temp;
        } while (next_permutation(vcTemp.begin(), vcTemp.end()));
        cout << maxTemp << "\n";
    }
}
int main(){
    int n;
    vector<vector<int>> vc;
    cin >> n;
    for (int i=0; i<n; i++){
        vector<int> vcTemp;
        for (int j=0; j<4; j++){
            int temp;
            cin >> temp;
            vcTemp.push_back(temp);
        } 
        vc.push_back(vcTemp);
    }
    solve(vc, n); 
    return 0;
}      