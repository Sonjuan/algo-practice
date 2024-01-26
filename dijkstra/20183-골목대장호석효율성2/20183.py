from collections import defaultdict
from heapq import heappush, heappop
import sys
input = sys.stdin.readline

N, M, A, B, C = map(int, input().split())
graph = defaultdict(list)
edges = set()

for _ in range(M) :
    u,v,c = map(int, input().split())
    graph[u].append((v,c))
    graph[v].append((u,c))
    edges.add(c)

def path_finding(target_weight) :
    pq = [(0,A)]
    result = {i : float('inf') for i in range(1,N+1)}
    result[A] = 0

    while pq :
        w, cur = heappop(pq)
    
        if result[cur] < w :
            continue

        for nxt, nw in graph[cur] :
            if nw <= target_weight and w+nw < result[nxt] :
                result[nxt] = w+nw
                heappush(pq, (w+nw, nxt))

    if result[B] <= C :
        return result[B]
    else :
        return -1

left = 0
right = len(edges) -1
edges = sorted(list(edges))
ans = -1

while left <= right :
    mid = (left - right)//2 + right
    if path_finding(edges[mid]) != -1 :
        right = mid - 1
        ans = edges[mid] 
    else :
        left = mid + 1

print(ans)