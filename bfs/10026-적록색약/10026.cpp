#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N;
int M;
string table[102];
int vis[102][102];
int vis2[102][102];

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int bfs(int a, int b, char color) {
    if(color == 'B') vis2[a][b] = 1;
    vis[a][b] = 1;
    queue<pair<int,int>> q;
    q.push({a, b});

    while(!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if(table[nr][nc] != color) continue;
            if(vis[nr][nc]) continue;
            if(color == 'B') vis2[nr][nc] = 1;
            vis[nr][nc] = 1;
            q.push({nr, nc});
        }
    }
    return 1;
}

int main(void) {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> table[i];
    }
    M = table[0].size();

    int blue  = 0;
    int green = 0;
    int red   = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(vis[i][j]) continue;
            if(table[i][j] == 'B') blue += bfs(i, j, 'B');
            if(table[i][j] == 'R') red += bfs(i, j, 'R');
            if(table[i][j] == 'G') green += bfs(i, j, 'G');
        }
    }

    int blind = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(vis2[i][j]) continue;
            vis2[i][j] = 1;
            blind += 1;
            queue<pair<int,int>> q;
            q.push({i, j});
            while(!q.empty()) {
                auto [r, c] = q.front(); q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nr = r + dr[dir];
                    int nc = c + dc[dir];
                    if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
                    if(vis2[nr][nc]) continue;
                    vis2[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    cout << red+blue+green << " " << blue + blind;
    return 0;   
}