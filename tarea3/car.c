#include <stdio.h>
#include <math.h>
/*velocidad inicial = u, aceleracion constante = a, 
tiempo = t,  velocidad = v, desplazamiento = s
*/
int main(){

    int casos, contador = 0;
    scanf("%d", &casos);
    
    while(casos != 0){
        double number1, number2, number3, result1, result2;
        contador++;
        scanf("%lf %lf %lf", &number1, &number2, &number3);
        
        if(casos == 1){
            result1 = (number1+number2)/2*number3;
            result2 = (number2-number1)/number3;
            printf("Case %d: %.3lf %.3lf\n", contador, result1, result2);
            /* velocidad inicial, velocidad, tiempo 
            print(desplazamiento y aceleracion constante)*/
        }
        else if(casos == 2){
            result1 = ((number2*number2)-(number1*number1))/(2*number3);
            result2 = (number2-number1)/(number3);
            printf("Case %d: %.3lf %.3lf\n", contador, result1, result2);
            /* velocidad inicial, velocidad, aceleracion constante 
            print(desplazamiento y tiempo)*/
        }
        else if(casos == 3){
            result1 = sqrt((number1*number1)+2*(number2)*number3);
            result2 = (result1 - number1)/number2;
            printf("Case %d: %.3lf %.3lf\n", contador, result1, result2);
            /* velocidad inicial, aceleracion constante, desplazamiento
            print(velocidad y tiempo)*/
        }
            
        else if(casos == 4){
            result1 = sqrt((number1*number1)-2*(number2)*number3);
            result2 = (number1 - result1)/number2;
            printf("Case %d: %.3lf %.3lf\n", contador, result1, result2);
            /* velocidad, aceleracion constante, desplazamiento
            print(velocidad inicial, tiempo)*/
        }
        scanf("%d", &casos);

    }
    return 0;
}