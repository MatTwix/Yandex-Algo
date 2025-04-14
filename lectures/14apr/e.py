n, max_weight = map(int, input().split())
w = list(map(int, input.split()))
c = list(map(int, input().split()))

knapsack = [-1] * (max_weight + 1)
knapsack[0] = 0
for i in range(n):
    for now_weight in range(max_weight - w[i], -1, -1):
        if knapsack[now_weight] != -1:
            knapsack [now_weight + w[1]] = max(knapsack[now_weight + w[i]],knapsack [now_weight] + c[i])
ans = 0
for now_weight in range(max_weight, -1, -1):
    ans = max(ans, knapsack[now_weight])
print(ans)