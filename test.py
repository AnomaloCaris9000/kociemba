def permute(tab, perm):
    for i in range(len(table)):
        tab[i] = tab[perm[i]]


TAB = [0, 1, 2, 3]
PERM = [1, 0, 2, 3]


print(permute(TAB, PERM))