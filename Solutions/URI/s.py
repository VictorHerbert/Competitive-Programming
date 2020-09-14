#python s.py < in.txt > out.txt   

def minput(f):
    return [f(s) for s in input().split()]


a = int(input())
b = int(input())
c = int(input())

print(max(b,c,a-b-c))
