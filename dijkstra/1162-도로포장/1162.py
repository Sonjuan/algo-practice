from heapq import heappush, heappop
from collections import defaultdict
import sys

N, M, K = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(N+1)]

for _ in range(M) :
    u,v,c = map(int, sys.stdin.readline().split())
    graph[u].append((v,c))
    graph[v].append((u,c))

dist = [[float('inf')] * (K + 1) for _ in range(N+1)]
pq = []

for i in range(K+1) :
    dist[1][i] = 0

heappush(pq, (0,1,0))

while pq :
    cur_dist, node, k = heappop(pq)
    # eliminate arranged value
    if dist[node][k] < cur_dist :
        continue

    if k + 1 <= K :
        for (nxt, nxt_dist) in graph[node] :
            if dist[nxt][k+1] > cur_dist :
                dist[nxt][k+1] = cur_dist
                heappush(pq, (cur_dist, nxt, k+1))
    
    for (nxt, nxt_dist) in graph[node] :
        if dist[nxt][k] > cur_dist + nxt_dist :
            dist[nxt][k] = cur_dist +nxt_dist
            heappush(pq, (cur_dist+nxt_dist, nxt, k))

ans = float('inf')
for i in range(K+1) :
    ans = min(ans, dist[N][i])
print(ans)


# 1<=N<=10,000
# 1<=M<=50,000
# 1<=K<=20
# 1<=C<=1,000,000

