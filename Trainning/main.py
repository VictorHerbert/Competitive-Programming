#python main.py < ./input/in1.txt > ./output/out1.txt
from  bisect import bisect_right

def minput(f):
    return [f(s) for s in input().split()]

fib = [1,1]

while fib[-1] < 10**100:
    fib.append(fib[-1]+fib[-2])


while True:
    a,b = minput(int)
    if a == b == 0:
        break
    print(bisect_right(fib, b)-bisect_right(fib, a))
    
    