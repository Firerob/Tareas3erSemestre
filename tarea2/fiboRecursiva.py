def fiboRecursiva(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fiboRecursiva(n-1)+fiboRecursiva(n-2)

fiboRecursiva(30)



