/*
Autor: Daniel Felipe Moncada Tello
Username: chaufelipe
UVa:
*/

/*  Analisis de complejidad:
    el algoritmo tiene whiles anidados en la cual en cada iteracion ejecuta n veces
    una vez por cada persona y en el ciclo interno n veces en el peor caso, 
    lee los datos de cada persona y lo que pide el problema, busca al donado 
    correspondiente en el vector y establece los valores. 

    la complejidad del algoritmo seria de O(n^2)
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct amiguitos{
    string nombre;
    int plata;
};

int main(){

    int numPeople, rep, i;
    string names;
    bool saltoLinea = false;
    
    
    
    /*while que recoge el numero de personas y ejecuta mientras que no sea EOF*/
    while(cin >> numPeople && numPeople != EOF){
        if(saltoLinea == true){
            cout << "\n";
        }

        saltoLinea = true;
        rep = numPeople;
        vector<amiguitos> vec;
        /*while que recoge los nombres de cada amigo en su respectivo struct*/
        while(numPeople > 0){
            cin >> names;
            struct amiguitos amigo;
            amigo.nombre = names;
            amigo.plata = 0;
            vec.push_back(amigo);
            
            --numPeople;
        }

        /*while que repite las veces igual al numero de personas*/
        while(rep > 0){
            string donador, donado;
            int i, plata, plataDiv, plataRestante, numDonados;
            bool flag;

            cin >> donador >> plata >> numDonados;

            if(numDonados > 0){
                plataDiv = plata/numDonados;
                plataRestante = plata % numDonados;

                //while que reparte la plata dividida a cada donado/
                while(numDonados > 0){
                    cin >> donado;
                    i = 0;
                    flag = true;

                    //while que recorre el vector buscando al respectivo donado para hacer la donacion/
                    while(flag == true){
                        if(vec[i].nombre == donado){
                            vec[i].plata += plataDiv;
                            flag = false;
                        }
                        i++;
                    }
                    --numDonados;
                }

                flag = true;
                i = 0;

                /*while que busca al donador para restarle la plata donada y sumarle el sobrante*/
                while(flag == true){
                    if(vec[i].nombre == donador){
                        vec[i].plata -= plata;
                        vec[i].plata += plataRestante;
                        flag = false;
                    }
                    i++;
                }
            }

            else if(numDonados = 0 && plata > 0){
                flag = true;
                i = 0;
                while(flag = true){
                    if(vec[i].nombre == donador){
                        vec[i].plata += plata;
                    }
                    ++i;
                }
            }
            --rep;

        }

        for(i = 0; i < vec.size(); ++i){
            cout << vec[i].nombre << " " << vec[i].plata << endl;
        }
        vec.clear();
    }

    return 0;
}
