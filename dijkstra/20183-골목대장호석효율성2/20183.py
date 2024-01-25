from collections import defaultdict
from heapq import heappush, heappop
import sys
input = sys.stdin.readline

N, M, A, B, C = map(int, input().split())
graph = defaultdict(list)

for _ in range(M) :
    u,v,c = map(int, input().split())
    graph[u].append((v,c))
    graph[v].append((u,c))

result = {i : float('inf') for i in range(1,N+1)}
result[A] = 0
ans = float('inf')
pq = [(0, A, 0)]

while pq :
    w, cur, mw = heappop(pq)
    if cur == B :
        if w <= C :
            ans = min(ans,mw)
            
        continue
    
    if result[cur] < w :
        continue

    for nxt, nw in graph[cur] :
        if w + nw < result[nxt] :
            result[nxt] = w + nw
            heappush(pq, (w+nw, nxt,max(mw,nw)))

if ans != float('inf'):
    print(ans)
else :
    print(-1)