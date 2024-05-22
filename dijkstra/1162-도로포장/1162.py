


from heapq import heappush, heappop
from collections import defaultdict

N, M, K = map(int, input().split())

graph = defaultdict(list)

for _ in range(M) :
    u,v,c = map(int, input().split())
    graph[u].append((v,c))
    graph[v].append((u,c))





# 1<=N<=10,000
# 1<=M<=50,000
# 1<=K<=20
# 1<=C<=1,000,000

