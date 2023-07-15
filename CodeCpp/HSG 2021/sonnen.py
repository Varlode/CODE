n = int(input())
f1 = 1
f2 = 1
if n <= 2:
    print(1)
else:
    for i in range(2, n):
        fn = f1 + f2
        f1 = f2
        f2 = fn
    print(fn)