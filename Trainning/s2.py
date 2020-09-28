from math import e,pi
import cmath
import numpy as np

def pol(r,g):
    a = g*pi/180
    return r*e**(a*1j)

def deg(c):
    r,a = cmath.polar(c)
    a*=180/pi
    return r,a


def parallel(a,b):
    return (a**-1+b**-1)**-1

def cap(w,c):
    return -1j/(w*c)

def ind(w,l):
    return 1j*w*l

def invcap(f,x):
    return -1j/(2*pi*f*x)

def invind(f,x):
    return 1j*x/(2*pi*f)

A = np.array([
    [-10+1/(5j)+1/(30+5j),0],
    [1,-1]

])

B = np.array([
    [(10j)/(30+5j)],
    [10j]
])

v = np.linalg.solve(A,B)


print(deg(v[1][0]/(100j)))

z = parallel(5j,30+5j)

v = z/(1-10*z)
print(v)

