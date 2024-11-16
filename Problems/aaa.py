for i in range(1, 10000, 2):
    for j in range(0, 10000, 2):
        # check if i and j are squares
        if i >= j:
            continue
        k = j - i
        if i == int(i**0.5) ** 2 and j == int(j**0.5) ** 2 and k == int(k**0.5) ** 2:
            print(i, j, k)
            break
