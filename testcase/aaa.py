import sys

s = sys.stdin.readline().strip('\n')
strs = s.split(' ')
kvs = strs[2].split(strs[0])
temp = []
c = 0
for it in kvs:
    kk = it.split(strs[1])
    if len(kk) == 2 and len(kk[0]) > 0 and len(kk[1]) >0:
        c += 1
        temp.append(kk[0]+' '+kk[1])

print(c)
for i in temp:
    print(i)