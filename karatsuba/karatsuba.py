from math import ceil, floor

def karatsuba(a,b):
    if a < 10 and b < 10: # n = 1 -> O(1)
        return a*b

    n = max(len(str(a)), len(str(b))) #O(n)
    m = ceil(n/2) #O(1)

    w = floor(a/(10**m)) #O(1)
    x = a % (10**m) #O(1)
    y = floor(b/(10 ** m)) #O(1)
    z = b % (10**m) #O(1)

    wy = karatsuba(w,y) #T(n/2)
    xz = karatsuba(x,z) #T(n/2)
    wzxy = karatsuba(w+x, y+z) - wy - xz #T(n/2)

    return wy*(10**(m*2)) + wzxy*(10**m) + xz

print(karatsuba(3141592653589793238462643383279502884197169399375105820974944592
,2718281828459045235360287471352662497757247093699959574966967627))