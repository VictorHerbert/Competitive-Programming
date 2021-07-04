#python s.py < ./io/in.txt > ./io/out.txt
def minput(f):
    return [f(s) for s in input().split()]