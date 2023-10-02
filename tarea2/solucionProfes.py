import math

def mostrarDivisores(N):
    divs1, divs2, ac = [], [], 0
    i = 1
    while i * i <= N:
        if N % i == 0:
            divs1.append(i)
            divs2.append(N // i)
            ac += divs1[-1] + divs2[-1]
        i += 1
    print("Divisores número %d:" % N)
    for i in range(len(divs1)):
        print(" --> %d," % divs1[i])
    ini = len(divs2) - 1 if divs2[-1] != divs1[-1] else len(divs2) - 2

    for i in range(ini, -1, -1):
        if i > 0: print(" --> %d," % divs2[i])
        else: print(" --> %d" % divs2[i])
    print()
    print("Suma de los divisores del número %d: %d" % (N, ac))

n = 1000000000
mostrarDivisores(n)