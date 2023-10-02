#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int reverso(long long int entradaOri){
    
    long long int digitos, reverso = 0; 
                                              
    while(entradaOri != 0){               
        digitos = entradaOri % 10;             
        entradaOri = entradaOri / 10;
        reverso = reverso * 10 + digitos;                                 
    }
    return reverso;  
}

int palindromo(long long int entradaOri, long long int numreves){
    int ans = 0;
    if(entradaOri == numreves){
        ans = 1;
    }
    return ans;
}

int main(){
    int i = 0, j = 0, contador, casos, wachi;
    long long int entradaOri, numReves; 
    
    scanf("%d", &casos);
    while(i < casos){
        scanf("%lld", &entradaOri);
        numReves = reverso(entradaOri);
        wachi = palindromo(entradaOri, numReves);
        contador = 0;
        while(wachi != 1){
            entradaOri = entradaOri + numReves;
            numReves = reverso(entradaOri);
            wachi = palindromo(entradaOri, numReves);
            contador++;
        }
        printf("%d %lld\n", contador, entradaOri);

        i++;
    }
    return 0;
}