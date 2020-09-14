abc = 'abcdefghijklmnopqrstuvwxyz'

while True:
    try:
        s = input().replace(' ','')
        
        l = {}
        for c in abc:
            l[c] = False
        for c in s:
            l[c] = True
        a = []
        b = []
        for key, value in l.items():
            if(value):
                b.append(key)
            else:
                if(b != []):
                    a.append(b)
                    b = []
        if(b != []):
            a.append(b)
            b = []
        
        k = []
        for b in a:
            k.append('{}:{}'.format(b[0],b[-1]))
        print(', '.join(k))
    except EOFError:
        break
