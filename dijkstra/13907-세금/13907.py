from sys import stdin
from heapq import heappush, heappop

N, M, K = map(int, stdin.readline().split())
S, D = map(int, stdin.readline().split())

graph = [[]  for _ in range(N+1)]
for i in range(M) :
    a,b,w = map(int, stdin.readline().split())
    graph[a].append((b,w))
    graph[b].append((a,w))

ktable = [0] + [int(stdin.readline()) for i in range (K)]

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
        if nxt_dist + w >= dist[nxt][k+1] :
            continue
        
        flag = False
        for i in range(k+1) :
            if dist[nxt][i] <= nxt_dist+w :
                flag = True
                break
        if flag == True :
            continue

        dist[nxt][k+1] = nxt_dist + w
        if nxt == D :
            continue
        heappush(pq, (w+nxt_dist, nxt, k+1))

for i in range (K+1) :
    ans = float('inf')
    for k in range(N) :
        if dist[D][k] == float('inf') :
            continue
        dist[D][k] = dist[D][k] + ktable[i]*k
        ans = min(ans, dist[D][k])
    print(ans)

# 2<=N<=1000
# 1<=M<=30000
# 0<=K<=30000
# 1<=p<=10