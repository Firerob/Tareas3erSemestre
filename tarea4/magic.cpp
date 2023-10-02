/*
Autor: Daniel Felipe Moncada Tello
Username: chaufelipe
UVa: 10978 Let's Play Magic!


    Analisis de complejidad:
    El algoritmo tiene un ciclo anidado que se ejecuta n veces en el peor caso. 
    El primero que se utiliza para leer los datos de cada carta se ejecuta n veces. 
    El segundo que se ejecuta n veces en el peor caso ya que el vector estará lleno de 
    cartas.

    La complejidad temporal del algoritmo seria de O(n^2)
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(){
    int i, j, contador, cartas, tamano;
    bool flag, ans;
    string card, word;
    

    while(cin >> cartas && cartas != 0){
        vector<string>vec(cartas);
        i = 0;
        j = 0;
        while(j < cartas){
            cin >> card >> word;
            tamano = word.size();

            ans = true;
            contador = 1;
            while(tamano > 0 && ans != false){
                if(contador == tamano){
                    while(ans != false){
                        if(vec[i] == ""){
                            vec[i] = card;
                            ans = false;
                        }
                        else{
                            i = (i+1)%cartas;
                        }
                    }
                }

                if(vec[i] == ""){
                    ++contador;
                }

                i = (i+1)%cartas;

            }
            ++j;
        }

        for(int print = 0; print < vec.size(); ++print){
            cout << vec[print];
            if(print < vec.size() - 1){
                cout << " ";
            }
            else{
                cout << endl;
            }
        }
        

    }

    return 0;
}
