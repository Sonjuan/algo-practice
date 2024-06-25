from sys import stdin
from heapq import heappush, heappop

N, M, K = map(int, stdin.readline().split())
S, D = map(int, stdin.readline().split())

graph = [[]  for _ in range(N+1)]
for i in range(M) :
    a,b,w = map(int, stdin.readline().split())
    graph[a].append((b,w))
    graph[b].append((a,w))

ktable = [int(stdin.readline()) for i in range (K)]

dist = [[float('inf')] * (N) for _ in range(N+1)]
dist[S][0] = 0

pq = []
heappush(pq, (0, S, 0))
while pq :
    w, node, k = heappop(pq)
    if dist[node][k] != w :
        continue

    for (nxt, nxt_dist) in graph[node] :
        if k + 1 == N :
            continue
        if (min(dist[nxt][:k+2]) <= w + nxt_dist) :
            continue

        dist[nxt][k+1] = w + nxt_dist

        if nxt == D :
            continue
        heappush(pq, (w+nxt_dist, nxt, k+1))

cost = []
for i in range(N) :
    if dist[D][i] != float('inf') :
        cost.append([dist[D][i], i])
print(min(dist[D]))

for i in range (K) :
    ans = float('inf')
    for j in range(len(cost)) :
        cost[j][0] += cost[j][1] * ktable[i]
        ans = min(ans, cost[j][0])
    print(ans)

# 2<=N<=1000
# 1<=M<=30000
# 0<=K<=30000
# 1<=p<=10