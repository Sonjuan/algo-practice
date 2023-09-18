#include <iostream>
#include <queue>

using namespace std;

int T;
int N;
int M;
int K;
int table[52][52];
int vis[52][52];

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int bfs(int a, int b) {
    vis[a][b] = 1;
    queue<pair<int, int>> q;
    q.push({a, b});

    while(!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if(vis[nr][nc]) continue;
            if(table[nr][nc] == 0) continue;
            vis[nr][nc] = 1;
            q.push({nr, nc});
        }
    }
    return 1;
}

int main(void) {
    cin >> T;
    while(T--) {
        cin >> M >> N >> K;
        for(int i = 0; i < 52; ++i) fill(table[i], table[i]+52, 0);
        for(int i = 0; i < 52; ++i) fill(vis[i], vis[i]+52, 0);

        while(K--) {
            int b, a;
            cin >> b >> a;
            table[a][b] = 1;
        }

        int ans = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(table[i][j] == 0) continue;
                if(vis[i][j]) continue;
                ans += bfs(i, j);
            }
        }
        cout << ans << endl;
    }
    return 0;
}