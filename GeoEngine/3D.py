import graphics as g

import random, time
import numpy as np
import sympy  as sp

win = g.GraphWin("Window", 600, 400)
pivot = [300,200]

icos = [
    [1,0,0],
    [0,1,0],
    [0,0,1],
    [-1,0,0],
    [0,-1,0],
    [0,0,-1],
]

def randColor():
    r = random.randrange(256)
    b = random.randrange(256)
    g = random.randrange(256)
    return color_rgb(r, g, b)

def drawTriangle(v):
    global win    
    xs = [v[0][0],v[1][0],v[2][0]]
    ys = [v[0][1],v[1][1],v[2][1]]
    print(xs,ys)

    x_min = min(xs)
    x_max = max(xs)
    y_min = min(ys)
    y_max = max(ys)

    tri = sp.Polygon(v[0],v[1],v[2])
    print(x_min,x_max,y_min,y_max)
    for i in range(x_min-1, x_max):
        for j in range(y_min-1, y_max):
            if tri.encloses_point(sp.Point(i,j)):
                pt = g.Point(i,j)
                pt.setFill('blue')
                pt.draw(win)

def main():
    global win
    
    win.setBackground('black')
    
    drawTriangle([(50,50),(90,40),(200,300)])
    print('done')
    win.getMouse()
    win.close()

main()


print()