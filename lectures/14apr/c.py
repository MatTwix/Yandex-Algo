m = int(input())
mb = list(map(int, input().split()))

for i in range (1, 31):
    mb[i] = max(mb[i], mb[i - 1] * 2)
now_cost = 0
ans = 10**18

for i in range(30, -1, -1):
    if m <= mb[i]:
        ans = min(ans, now_cost + 2**i)
    else:
        now_cost += 2**i
        m -= mb[i]
if m == 0:
    ans = min(now_cost, ans)

print(ans)