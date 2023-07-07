I = input().split()
t = []
for i in I:
    if i not in t:
        t.append(i)
I = t
TE = input().split()
TC = input().split(", ")
for i in range(len(TC)):
    TC[i] = TC[i].split()
TW = input().split()
for q in range(len(TW)):
    TW[q] = float(TW[q])
PN = input().split()
PD = input().split(", ")
for k in range(len(PD)):
    PD[k] = PD[k].split()
    PD[k].sort()
BP = []
Invalid = []
for e in range(len(TE)):
    BP.append([])
for x in range(len(I)):
    fl = True
    if len(I[x]) != 4:
        fl = True
    else:
        for f in range(len(TE)):
            if I[x][0:2] in TC[f]:
                BP[f].append(I[x])
                fl = False
    if fl:
        Invalid.append(I[x])
PiD = []
for i in TE:
    PiD.append([])
for j in range(len(TE)):
    for k in range(len(PD)):
        if TE[j] in PD[k]:
            PiD[j].append(PN[k])
R = []
for i in range(len(PN)):
    R.append([])
for k in range(len(BP)):
    if len(PiD[k]) == 1:
        a = PN.index(PiD[k][0])
        for j in range(len(BP[k])):
            R[a].append(BP[k][j])
    else:
        c = []
        for i in range(len(PiD[k])):
            c.append(0)
        for j in range(len(BP[k])):
            a = c.index(min(c))
            R[a].append(BP[k][j])
            c[a] += 1
print()
for i in range(len(R)):
    R[i].sort()
PNAlpha = PN.copy()
PNAlpha.sort()
for m in range(len(PNAlpha)):
    wage = 0.0
    b = PN.index(PNAlpha[m])
    print(PNAlpha[m]+":")
    for o in range(len(PD[b])):
        e = TE.index(PD[b][o])
        print(PD[b][o]+":")
        print("    ", end="")
        z = TE.index(PD[b][o])
        for t in range(len(R[b])):
            if R[b][t][0:2] in TC[z]:
                print(R[b][t], end=" ")
                wage += TW[z]
        print()
    print("Wage = $"+str(wage)+'\n\n')
print("Invalid postal codes:")
print("    ", end="")
for i in Invalid:
    print(i, end=" ")
