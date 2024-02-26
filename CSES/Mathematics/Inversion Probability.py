from math import gcd
n = int(input())
r = [int(i) for i in input().split()]
(num, den) = (0, 1)
for i in range(0, n):
    for j in range(0, i):
        tot = r[i] * r[j]
        if r[j] < r[i]:
            fav = r[j] * (r[j] - 1) // 2
        else:
            fav = r[i] * (r[i] - 1) // 2 + r[i] * (r[j] - r[i])
            
        (num, den) = (num * tot + fav * den, den * tot)
        common_factor = gcd(num, den)
        num //= common_factor
        den //= common_factor
        
res = num / den
print('%.6f' % res)