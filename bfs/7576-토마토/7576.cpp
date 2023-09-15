#include <iostream>
#include <queue>
using namespace std;

int N;
int M;
int table[1005][1005];
int dist[1005][1005];
int Max;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int main(void) {
    cin >> M >> N;

    for(int i = 0; i < 1005; ++i) fill(dist[i], dist[i]+1005, -1);
    
    queue<pair<int,int>> q;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> table[i][j];
            if(table[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while(!q.empty()) {
        auto [r, c] = q.front(); q.pop();

        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if(table[nr][nc] == -1) continue;
            if(dist[nr][nc] != -1) continue;

            dist[nr][nc] = dist[r][c] + 1;
            table[nr][nc] = 1;
            q.push({nr, nc});
        }
    }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(table[i][j] == 0) {
                cout << -1;
                return 0;
            }
            Max = max(Max, dist[i][j]);
        }
    }

    cout << Max;

    return 0;
}