#python main.py < ./input/in1.txt > ./output/out1.txt
def minput(f):
    return [f(s) for s in input().split()]