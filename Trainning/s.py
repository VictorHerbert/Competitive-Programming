#python s.py < ./io/in.txt > ./io/out.txt

import datetime

def minput(f):
    return [f(s) for s in input().split()]
