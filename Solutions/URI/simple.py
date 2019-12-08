n = 0
acum = 0
while(True):
    try:
        n += 1
        input()
        acum += int(input())
    except EOFError:
        break

print('{:.1f}'.format(acum/n))