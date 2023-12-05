#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//Basicamente lo que se busca es formar un triangulo desde arriba, ir expandiendose hacia los costados si es posible
//Una vez se llega a la base (es decir a la cantidad de hobbits) la unica forma de aumentar las almohadas para frodo
//seria sumar a la base o aumentarle una almohada a todos, que necesitaria la misma cantidad de almohadas
void solve(ll h, ll p, ll k){
    //Primero se inicia los extremos de expansion en el mismo numero
    ll r = k; ll l = k;
    ll max = 1; //Para este momento si o si el numero de almohadas para frodo es 1
    p = p - h; //Se resta del numero de almohadas el total de hobbits
    if (p != 0)  {
        ll temp = 1; //Primero si es que aun sobran almohadas primero se le da una a frodo
        while (p - temp >= 0){ //Verifica si siguen sobrando almohadas
            p = p - temp; //Se restan las almohadas 
            max++; //Aumetna el tamaño
            if (abs(r-l)+1 == h){ //Si es que los extremos llegaron a ocupar todas las camas, entonces para poder aumentar las almohadas de frodo
            //Se debera aumentar a todos los hobbits una almohada floor(p/h) veces
            //Y cada vez que se aumente se sumara al numero de la cantidad de maximas
                if ((p) % h != 0){
                    p = p - ((p)%h);
                }
                max += (p)/h;
                break;
            }   
            //Se expande si es posible
            if (r < h-1)  r++;
            if (l > 0)  l--;  
            //Se actualiza la cantidad de almohadas necesiarias
            temp = (abs(r-l)+1);    
        }   
    }
    cout << max << "\n";
}
//La complejidad es muy probable que sea O(n) -> n sea igual al numero de hobbits, uno de los peores casos es que el k, la cama de frodo
//sea n o 0, aumentara de 1 en 1 el left o rigth, hasta llegar a ser igual a h el temp, donde solo se hace una division y se termian el while
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n; ll m; ll k;
    cin >> n >> m >> k;
    solve(n, m, k-1);
    return 0;
}      