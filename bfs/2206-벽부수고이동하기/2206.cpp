#include <bits/stdc++.h>
using namespace std;

int board[1002][1002];
int dist[1002][1002][2];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main(void) {
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> board[i][j];
            dist[i][j][0] = dist[i][j][1] = -1;
        }
    }
    dist[0][0][0] = dist[0][0][1] = 1;
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    while(!q.empty()) {
        int x, y, broken;
        tie(x, y, broken) = q.front();
        if(x == n-1 && y == m-1) return dist[x][y][broken];
        q.pop();
        for(int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(x < 0 || x >= n || y < 0 || y >= m) continue;
            if(board[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
                dist[nx][ny][broken] = dist[x][y][broken] + 1;
                q.push({nx, ny, broken});
            }
            if(!broken && board[ny][nx] == '1' && dist[nx][ny][broken] == -1 ) {
                dist[ny][nx][broken] = dist[x][y][broken] + 1;
                q.push({nx, ny, 1});
            }
        }    
    }
    return -1;
}