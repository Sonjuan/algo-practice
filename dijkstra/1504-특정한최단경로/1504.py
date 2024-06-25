from sys import stdin
from heapq import heappop, heappush

N, E = map(int, stdin.readline().split())

graph = [[] for _ in range(N+1)]

for _ in range(E) :
    a,b,c = map(int, stdin.readline().split())
    graph[a].append((b,c))
    graph[b].append((a,c))

v1, v2 = map(int, stdin.readline().split())

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
            
            if nxt == D :
                continue

            heappush(pq, (nxt_dist+w, nxt))
    return dist[D]


ans1 = Dijkstra(1, v1) + Dijkstra(v1,v2) + Dijkstra(v2, N)
ans2 = Dijkstra(1, v2) + Dijkstra(v2,v1) + Dijkstra(v1, N)

ans = min(ans1,ans2)
if ans == float('inf') :
    print(-1)
else :
    print(ans)

# 2<=N<=800
# 0<=E<=200,000
# 1<=c<=1,000
# v1 != v2 
# v1 != N 
# v2 != 1