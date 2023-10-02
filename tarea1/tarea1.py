"""
Estructuras de Datos 2023-2
Profesor: Carlos Ramírez

Estudiante: Daniel Felipe Moncada Tello
Id: 8976528
"""


### Punto 1

def split(cad, sep):

    lista = []
    inicio = 0
    i = 0
    while i < len(cad):
        if cad[i] == sep:
            var = cad[inicio:i]
            lista.append(var)
            inicio = i + 1
        i += 1
    
    if inicio < len(cad):
        lista.append(cad[inicio:])
    
    while '' in lista:
        lista.remove('')

    return lista

split("hola mundo bonito!", "o")


### Punto 2

mat = [[10, 10, 5, 20],
       [14, 30, 92, 30],
       [12, 45, 58, 40],
       [20, 20 , 20, 20]]

def obtenerSumas(mat):

    n = len(mat)
    lista = []

    for i in range(2 * n - 1):
        contador = 0

        for j in range(n):
            var = i - j
            if var >= 0 and var < n:
                contador += mat[j][var]

        lista.append(contador)

    return lista

obtenerSumas(mat)

### Punto 3

def obtenerMayorPosicion(cad1, cad2):
    listaCad = list(cad2)
    listaPosiciones = []

    i = 0
    while i < len(listaCad):
        if listaCad[i] in cad1:
            x = cad1.rfind(listaCad[i])
            listaPosiciones.append(x)

        else:
            listaPosiciones.append(-1)

        i += 1
    dicc = {listaCad:listaPosiciones for (listaCad, listaPosiciones) in zip(listaCad, listaPosiciones)}

    return dicc

obtenerMayorPosicion("mi corazon encantado vibra por el polvo de esperanza y magia!!", "za!em iolpx")

### Punto 4

def obtenerDosMayores(l):
    lMayores = []
    l.sort()
    lMayores.append(l[-1])
    lMayores.append(l[-2])
    tupla = tuple(lMayores)
    return tupla
       
obtenerDosMayores([40, 10, 22, 12, 33, 33, 33, 39, 54])

def lecturaImpresion():
    i = 0
    lista1 = []
    lista2 = []
    veces = int(input())
    while i < veces:
        linea1 = list(map(int, input().split()))
        linea2 = list(map(int, input().split()))
        listaDef = linea1 + linea2
        result = obtenerDosMayores(listaDef)
        
        print("Primer valor mayor --> %d, Segundo valor mayor --> %d" % (result[0], result[1]))
        i += 1

lecturaImpresion()

### Punto 5

def mostrarDivisores(n):
    contador = 0
    print("Divisores numero %d:" %n)
    for i in range(1, n):
        if (n % i) == 0:
            contador += i
            print("--> %d," %i)
    print("--> %d" %n)   
    
    contador = contador + n
    print("\nSuma de los divisores del numero %d: %d" % (n, contador))


mostrarDivisores(1000)