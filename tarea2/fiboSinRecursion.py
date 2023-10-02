def fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    
    numero_anterior = 0
    numero_actual = 1
    
    for i in range(2, n + 1):
        numero_futuro = numero_actual + numero_anterior
        numero_anterior = numero_actual
        numero_actual = numero_futuro
        
    return numero_actual

print(fibonacci(10000))