
def van_dung_16_2():
    for i in range(1, 11):
        for j in range(2, 9):
            print(j, " x ", i, " = ", i*j, end='')
            print(" ", end='')
        print("9 x ", i, " = ", i*9)

def van_dung_17_1():
    ss = int(input())
    mot_ngay = 86400
    mot_gio = 3600
    mot_phut = 60
    print(ss, " giay = ", end='')
    if (ss >= mot_ngay):
        print(ss // mot_ngay, "ngay ", end='')
    ss -= ss // mot_ngay * mot_ngay
    if (ss >= mot_gio):
        print(ss // mot_gio, "gio ", end='')
    ss -= ss // mot_gio * mot_gio
    if (ss >= mot_phut):
        print(ss // mot_phut, "phut ", end='')
    ss -= ss // mot_phut * mot_phut
    if (ss > 0):
        print(ss, "giay")
# dong  thoi la van dung bai 18

def van_dung_19_1():
    soky = int(input())
    if (soky >= 5):
        print(soky * 10000)
    else:
        print(soky * 12000)

def van_dung_19_2():
    n = int(input())
    if (n % 400 == 0) | ((n % 4 == 0) & (n % 100 != 0)):
        print(n, " la nam nhuan")
    else:
        print(n, " khong la nam nhuan")

def van_dung_20_1():
    n = int(input())
    s = float(0)
    for i in range(1, n+1):
        s += 1 / i
    print(s)

def van_dung_20_2():
    n = int(input())
    s = 0
    for i in range(1,n+1):
        s += i**3
    print(s)

def van_dung_21_0():
    for i in range(0,10):
        for j in range(1,11):
            print(j+i*10, end='')
            if (j != 10):
                print(" ", end='')
        print()

def van_dung_22_0():
    s = input()
    a = []
    res1 = 0
    res2 = 10**6
    a = s.split( )
    for i in range(len(a)):
        res1 = max(res1, int(a[i]))
        res2 = min(res2, int(a[i]))
    print("max :", res1)
    print("min :", res2)

def van_dung_23_1():
    n = int(input())
    n += n
    for i in range(1, n+1):
        if i % 2 == 0:
            print(i, " ", end='')

def van_dung_23_2():
    n = int(input())
    if n < 2:
        print(n)
        exit()
    f0 = 0
    f1 = 1
    fn = n
    for i in range(2, n+1):
        fn = f0 + f1
        f0 = f1
        f1 = fn
    print(fn)

def van_dung_24_1():
    s1 = input()
    s2 = input()
    s2 = s2[: len(s2) // 2] + s1 + s2[len(s2) // 2 :]
    print(s2[len(s2) // 2])

print('%.2f %.3f' % (12.1, 12.2))