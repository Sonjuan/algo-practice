#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N;
int M;
string table[102];
int vis[102][102];

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int bfs(int a, int b) {
    vis[a][b] = 1;
    queue<pair<int,int>> q;
    q.push({a, b});

    while(!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if(table[nr][nc] != table[r][c]) continue;
            if(vis[nr][nc]) continue;
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
            if(table[i][j] == 'B') blue += bfs(i, j);
            if(table[i][j] == 'R') red += bfs(i, j);
            if(table[i][j] == 'G') green += bfs(i, j);
        }
    }

    for(int i = 0; i < N; ++i) {
        fill(vis[i], vis[i]+102, 0);
        for(int j = 0; j < M; ++j) {
            if(table[i][j] == 'G') table[i][j] = 'R';
        }
    }

    int blind = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(vis[i][j]) continue;
            blind += bfs(i, j);
        }
    }

    cout << red+blue+green << " " << blind;
    return 0;   
}