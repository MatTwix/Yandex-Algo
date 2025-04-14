n, max_weight = map(int, input().split())
w = list(map(int, input().split()))

knapsack = [0] * (max_weight + 1)
knapsack[0] = 1

for i in range(n):
    for now_weight in range(max_weight - w[i], -1, -1):
        if knapsack[now_weight] == 1:
            knapsack[now_weight + w[i]] = 1

for now_weight in range(max_weight, -1, -1):
    if knapsack[now_weight] == 1:
        print (now_weight)
        break