t = int(input())
for _ in range(t):
    k, q = map(int, input().split())
    a = list(map(int, input().split()))
    n = list(map(int, input().split()))
    a.append(101)
    for ni in n:
        if ni < a[0]:
            print(ni)
        else:
            l = 0
            r = k
            while l < r:
                mid = (l + r + 1) // 2
                if a[mid] - mid <= ni:
                    l = mid
                else:
                    r = mid - 1
            print(ni + l + 1)
