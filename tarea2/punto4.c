#include <stdio.h>
#include <math.h>

void algoritmo1(int n){
    int i, j = 1;
    for(i = 1; i < n * n; i = i * 3){
        int suma = i + j;
        printf("Suma %d\n", suma);
        ++j;
    }
}

/*int algoritmo2(int n){
    int res = 1, i, j, cont = 1, wa = 1;
    for(i = 1; i <= 3 * n; i += 5){
        printf("wachi wa: %d\n", wa);
        ++wa;
        for(j = 0; j <= sqrt(n); j++){
            printf("cont: %d\n", cont);
            ++cont;
            res += n;
            
        }
    }   
    return res;
}
*/

int algoritmo2(int n){
    int res = 1, i, j;
    for(i = 1; i <= 3 * n; i += 5)
        for(j = 0; j <= sqrt(n); j++)
            res += n;
    
    printf("res: %d", res);
    return res;
}

void algoritmo3(int n){
    int i, j, k, cont1 = 1, cont2 = 1, cont3 = 1;
    for(i = 1; i <= n + 2; ++i){
        printf("contador1: %d\n", cont1);
        ++cont1;
        for(j = 1; j <= i; j++){
            printf("contador2: %d\n", cont2);
            ++cont2;
            for(k = 0; k < n; k++){
                printf("contador3: %d\n", cont3); 
                ++cont3;
            }
                
        }
    }

}

int algoritmo4(int k, int* A, int n){
    int suma = 0, contador = 0;
    int i, j, h, flag;

    for(i = 0; i < n; i++){
        j = i;
        flag = 1;
        while(j < n && flag == 1){
            if(A[j] == k){
                contador++;
                flag = 0;
                }
            else{
                for(h = n - 1; h >= j; h--){
                    suma += A[h];
                }
            }
            ++j;
        }
    }
    return contador;
}

void algoritmo5(unsigned int n){
    int i = n;
    while(i > 0){
        printf("%d\n", i);
        i -= n / 4;
    }
}


void algoritmo6(int n){
    int i, j = 1;
    for(i = n * n; i > 0; i = i / 2){
        int suma = i + j;
        printf("Suma %d\n", suma);
        ++j;
    }
}

int algoritmo7(int n){
    int res = 1, i, j;
    for(i = 1; i <= 2 * n; i += 4){
        for(j = 1; j * j <= n; j++){
            res += 2;
            printf("%d\n", res);
            }
    }
    return res;
}

int main(){
    algoritmo7(9);
    
    return 0;
}