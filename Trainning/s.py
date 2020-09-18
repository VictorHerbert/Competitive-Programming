from math import e,pi
import cmath
import numpy as np

def p(r,g):
    a = g*pi/180
    return r*e**(a*1j)

def deg(c):
    r,a = cmath.polar(c)
    a*=180/pi
    return r,a


vg = p(100,30)
i0 = p(10,10)


A = np.array([
    [-2-4j,-2,0,4j],
    [0,1,0,0],
    [4j,-2j,2j+1,1-4j],
    [0,0,-1,1]
])

B = np.array([
    [p(10,90)],
    [-2],
    [0],
    [-4]
])

v = np.linalg.solve(A,B)

print(v)
print(deg(v[0][0]))