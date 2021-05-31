def sumar(A, B): #O(n^2)
    n = len(A) #O(n)
    C = [[0 for j in range(0,n)] for i in range(0,n)] #O(n^2)
    for i in range(0,n): #O(n^2)
        for j in range(0,n):
            C[i][j] = A[i][j] + B[i][j]

    return C


def restar(A, B): # O(n^2)
    n = len(A)  # O(n)
    C = [[0 for j in range(0, n)] for i in range(0, n)]  # O(n^2)
    for i in range(0, n):  # O(n^2)
        for j in range(0, n):
            C[i][j] = A[i][j] - B[i][j]

    return C

def multiplicacion_bruta(A,B): #O(n^3)
    n = len(A)
    C = [[0 for j in range(n)] for i in range(n)]
    for i in range(n):
        for k in range(n):
            for j in range(n):
                C[i][j] += A[i][k] * B[k][j]

    return C

def strassen(A,B):
    n = len(A)

    if n <= 4:
        return multiplicacion_bruta(A,B)
    else:
        m = n//2
        a = [[0 for j in range(0, m)] for i in range(0, m)] #O(n^2)
        b = [[0 for j in range(0, m)] for i in range(0, m)]
        c = [[0 for j in range(0, m)] for i in range(0, m)]
        d = [[0 for j in range(0, m)] for i in range(0, m)]

        e = [[0 for j in range(0, m)] for i in range(0, m)]
        f = [[0 for j in range(0, m)] for i in range(0, m)]
        g = [[0 for j in range(0, m)] for i in range(0, m)]
        h = [[0 for j in range(0, m)] for i in range(0, m)]
