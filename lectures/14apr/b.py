t = int(input())
for test in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    prev_break = 0
    cur_min = a[0]
    ans = []
    for i in range(n):
        cur_min = min(cur_min, a[i])
        if prev_break + cur_min <= i:
            ans.append(i - prev_break)
            prev_break = i
            cur_min = a[i]
ans.append(n - prev_break)
print(len(ans))
print(*ans)