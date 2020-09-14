from math import atan

bt_size = 8
a = .6073

x = [1]
y = [0]
z = [45]
t = [atan(2**(-i))*360/(2*3.1415) for i in range(bt_size)]
print(t)

for i in range(bt_size):
    d = -1 if(z[-1] < 0) else 1
    z.append(z[-1]-d*t[i])

    x.append(x[-1] - y[-1]*d*2**(-i))
    y.append(y[-1] + x[-2]*d*2**(-i))


print(z)
print(a*x[-1],a*y[-1])
    
