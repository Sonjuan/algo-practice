#include <iostream>
#include <queue>

using namespace std;

int N;
int M;
int paint[502][502];
int vis[502][502];

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int ans;
int cnt;

int bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push({a, b});
    vis[a][b] = 1;
    int s = 1;
    while(!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(!paint[nr][nc]) continue;
            if(vis[nr][nc]) continue;
            vis[nr][nc] = 1;
            s += 1;
            q.push({nr, nc});
        }
    }
    return s;
}

int main(void) {
    cin >> N >> M;
    for(int i = 0;i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> paint[i][j];
        }
    }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(!paint[i][j]) continue;
            if(vis[i][j]) continue;
            ans = max(ans, bfs(i,j));
            cnt += 1;
        }
    }

    cout << cnt << endl;
    cout << ans << endl;

    return 0;
}