from heapq import heappush,heappop
import sys

input = sys.stdin.readline

N, M = map(int, input().split())

edges = [[] for _ in range(N+1)]

for i in range(M) :
    u, v = map(int, input().split())
    edges[u].append((i,v))
    edges[v].append((i,u))
    
dist = [float('inf') for _ in range(N+1)]
pq = []

heappush(pq,(0,1))
dist[1] = 0

while pq :
    w, cur = heappop(pq)
    if dist[cur] != w :
        continue

    for nw, v in edges[cur] :
        if nw < w :
            nw = nw + M
        
        nw = (nw - w) % M
        nw = nw + w

        if dist[v] < nw+1 :
            continue
        dist[v] = nw+1
        heappush(pq, (nw+1, v))

print(dist[N])
# print(dist)


# 출발점에서 시작한다
# 출발점으로부터 이어진 간선들을 검사한다
# 간선의 시작시간을 등록한다 (간선 시작시간 + 1 건너는시간)
# 우선순위 큐에서 가장 빠른 간선을 도출하고 해당 간선의 도착지점에서 추가로 간선을 큐에 넣는다
# PQ <- (w+1, v)
# 간선을 큐에 넣을 때 현재 w가 간선의 w보다 높다면 간선의 w를 인터벌만큼 증가시킨다
# dist를 기록해 중복을 방지한다

# if nw < w :
#    while nw < w :
#       nw = nw+M
        
# if dist[v] < nw+1 :
#    continue
# dist[v] = nw+1
# heappush(pq, (nw+1, v))
