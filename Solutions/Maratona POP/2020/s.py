#python s.py < ./io/in.txt > ./io/out.txt

import datetime

def minput(f):
    return [f(s) for s in input().split()]


s = input().split()

a = int(s[1])
b = int(s[2])

if s[0] == 'dom':
    print(' '.join(s))
else:

    
    d = {
        'seg' : 5,
        'ter' : 4,
        'qua' : 3,
        'qui' : 2,
        'sex' : 1,
        'sab' : 0,
    }

    date = datetime.datetime(2015,b,a) + datetime.timedelta(days=d[s[0]])
    print('sab',date.day,date.month)
