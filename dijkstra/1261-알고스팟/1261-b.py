from collections import deque
import sys
input = sys.stdin.readline

M,N = map(int, input().split())
board = []
for _ in range(N) :
    board.append(input())

q = deque()
q.append((0,0,0))

seen = set()

while q :
    r, c,w = q.popleft()

    if (r,c) == (N-1,M-1) :
        print(w)
        break

    if (r,c) in seen :
        continue
    seen.add((r,c))

    for ndr, ndc in [(0,1), (1,0), (0,-1), (-1,0)] :
        nr = r + ndr
        nc = c + ndc

        if 0 <= nr < N and 0 <= nc < M :            
            if board[nr][nc] == '0' :
                q.appendleft((nr,nc,w))
            else :
                q.append((nr,nc,w+1))
