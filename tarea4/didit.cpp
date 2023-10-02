/*
Autor: Daniel Felipe Moncada Tello
Username: chaufelipe
UVa: 11222	Only I did it!


    Analisis de complejidad:
    en la funcion comparador se hace uso de sort que tiene un costo de n*log n.
    Cada for recorre un vector y hace una búsqueda lineal en otros dos vectores. 
    Por lo tanto, la complejidad de cada bucle for es O(n^2) en el peor caso, donde n es 
    el numero de elementos en los vectores de cada amigo.

    la complejidad del algoritmo seria O(n^2)
*/

#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

void comparador(vector<vector<int>> problemas){
    vector<int> ganaAmigo1; 
    vector<int> ganaAmigo2; 
    vector<int> ganaAmigo3;
    vector<int> amigo1 = problemas[0];
    vector<int> amigo2 = problemas[1];
    vector<int> amigo3 = problemas[2];
    sort(amigo1.begin(), amigo1.end());
    sort(amigo2.begin(), amigo2.end());
    sort(amigo3.begin(), amigo3.end());
    int j;

    j = 0;
    for(int i = 0; i < amigo1.size(); ++i){
        int elementoBuscar = amigo1[i]; 
        vector<int>::iterator it1 = find(amigo2.begin(), amigo2.end(), elementoBuscar);
        vector<int>::iterator it2 = find(amigo3.begin(), amigo3.end(), elementoBuscar);
        if(it1 == amigo2.end() && it2 == amigo3.end() && (ganaAmigo1.size() == 0 || ganaAmigo1[j-1] != elementoBuscar)){
            ganaAmigo1.push_back(elementoBuscar);
            ++j;
            }
    }

    j = 0;
    for(int i = 0; i < amigo2.size(); ++i){
        int elementoBuscar = amigo2[i];
        vector<int>::iterator it1 = find(amigo1.begin(), amigo1.end(), elementoBuscar);
        vector<int>::iterator it2 = find(amigo3.begin(), amigo3.end(), elementoBuscar);
        if(it1 == amigo1.end() && it2 == amigo3.end() && (ganaAmigo2.size() == 0 || ganaAmigo2[j-1] != elementoBuscar)){
            ganaAmigo2.push_back(elementoBuscar);
            ++j;
        }
    }

    j = 0;
    for(int i = 0; i < amigo3.size(); ++i){
        int elementoBuscar = amigo3[i];
        vector<int>::iterator it1 = find(amigo1.begin(), amigo1.end(), elementoBuscar);
        vector<int>::iterator it2 = find(amigo2.begin(), amigo2.end(), elementoBuscar);
        if(it1 == amigo1.end() && it2 == amigo2.end() && (ganaAmigo3.size() == 0 || ganaAmigo3[j-1] != elementoBuscar)){
            ganaAmigo3.push_back(elementoBuscar);
            ++j;
        }
    }

    if(ganaAmigo1.size() >= ganaAmigo2.size() && ganaAmigo1.size() >= ganaAmigo3.size()){
        cout << 1 << " " << ganaAmigo1.size() << " ";
        for(int i = 0; i < ganaAmigo1.size(); ++i){
            cout << ganaAmigo1[i];
            if(i < ganaAmigo1.size() - 1){
                cout << " ";
            }
        }
        cout << endl;
    }

    if(ganaAmigo2.size() >= ganaAmigo1.size() && ganaAmigo2.size() >= ganaAmigo3.size()){
        cout << 2 << " " << ganaAmigo2.size() << " ";
        for(int i = 0; i < ganaAmigo2.size(); ++i){
            cout << ganaAmigo2[i];
            if(i < ganaAmigo2.size() - 1){
                cout << " ";
            }
        }
        cout << endl;
    }

    if(ganaAmigo3.size() >= ganaAmigo1.size() && ganaAmigo3.size() >= ganaAmigo2.size()){
        cout << 3 << " " << ganaAmigo3.size() << " ";
        for(int i = 0; i < ganaAmigo3.size(); ++i){
            cout << ganaAmigo3[i];
            if(i < ganaAmigo3.size() - 1){
                cout << " ";
            }
        }
        cout << endl;
    }
}


int main(){
    int i = 1, rep, cases, totalProblem, problemResueltos;

    cin >> cases;
    /*while que repite segun el numero de casos*/
    while(i <= cases){
        rep = 3;
        vector<vector<int>> problemas;

        /*while que repite para los 3 amigos*/
        while(rep > 0){
            vector<int> vec;

            cin >> totalProblem;
            /*while que recoge el total de problemas que resuelve cada amigo*/
            while(totalProblem > 0){
                cin >> problemResueltos;
                vec.push_back(problemResueltos);
                --totalProblem;
            }
            problemas.push_back(vec);
            --rep;
        }

        cout << "Case #" << i << ":" << endl;
        comparador(problemas);

        ++i;
    }

    return 0;
}