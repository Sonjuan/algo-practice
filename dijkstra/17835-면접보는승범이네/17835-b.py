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

pq = [(0,t) for t in targets]
seen = set()
result = []

while pq :
    w, cur = heappop(pq)

    if cur in seen :
        continue
    seen.add(cur)
    
    result.append((w, cur))

    for ncity, nw in graph[cur] :
        heappush(pq, (w+nw, ncity))        

max_v = max(result, key=lambda x:x[0])[0]
value, key = next(((v, k) for v, k in result if v == max_v))

print(key)
print(value)
