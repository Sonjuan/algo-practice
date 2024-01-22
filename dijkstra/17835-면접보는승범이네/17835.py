from heapq import heappush, heappop
from collections import defaultdict
import sys
input = sys.stdin.readline

N, M, K = map(int, input().split())
graph = defaultdict(list)

for _ in range(M) :
    u, v, c = map(int, input().split())
    graph[v].append((u,c))

targets = list(map(int, input().split()))
result = {i : float('inf') for i in range(1,N+1)}

pq = [(0,t) for t in targets]
for t in targets :
    result[t] = 0

while pq :
    w, cur = heappop(pq)
    if result[cur] < w :
        continue    
    
    for nxt in graph[cur] :
        ncity, nw = nxt
        if w + nw < result[ncity]:
            result[ncity] = w +nw
            heappush(pq, (w+nw, ncity))        

max_v = max(result.values())
for rc, rw in result.items() :
    if rw == max_v :
        print(rc)
        print(rw)
        break