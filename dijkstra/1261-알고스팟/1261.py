from heapq import heappush, heappop
M,N = map(int, input().split())

board = []
for _ in range(N) :
    board.append(input())

pq = [(0,0,0)]
seen = set()

while pq :
    wall, r, c = heappop(pq)

    if (r,c) == (N-1,M-1) :
        print(wall)
        break
    
    if (r,c) in seen :
        continue
    seen.add((r,c))
    
    for ndr, ndc in [(0,1), (1,0), (0,-1), (-1,0)] :
        nr = r + ndr
        nc = c + ndc

        if 0 <= nr < N and 0 <= nc < M :
            if board[nr][nc] == '1' :
                heappush(pq, (wall+1, nr,nc))
            else :
                heappush(pq,(wall,nr,nc))
