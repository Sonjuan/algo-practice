from sys import stdin
from heapq import heappop, heappush

N = int(stdin.readline())
M = int(stdin.readline())

graph = [[] for _ in range(N+1)]
for _ in range(M) :
    a,b,c = map(int, stdin.readline().split())
    graph[a].append((b,c))

v1,v2 = map(int, stdin.readline().split())

def Dijkstra(S, D) :
    dist = [float('inf') for _ in range(N+1)]
    dist[S] = 0

    pq =[]
    heappush(pq, (0, S))
    while pq :
        w, node = heappop(pq)
        if dist[node] != w :
            continue

        for (nxt,nxt_dist) in graph[node] :
            if dist[nxt] <= w + nxt_dist :
                continue
            dist[nxt] = w + nxt_dist
            heappush(pq, (nxt_dist+w, nxt))
    return dist[D]

print(Dijkstra(v1,v2))

# 1<=N<=1,000
# 1<=M<=100,000