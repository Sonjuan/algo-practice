#include <iostream>
#include <queue>
#include <string>
using namespace std;

int T;
int N;
int M;

int dist[1005][1005];
string table[1005];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int main(void) {
    cin >> T;
    while(T--) {
        cin >> M >> N;
        for(int i = 0; i < N; ++i) fill(dist[i], dist[i]+M, -1);
        for(int i = 0; i < N; ++i) cin >> table[i];
        
        queue<pair<int,int>> q1;
        queue<pair<int,int>> q2;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(table[i][j] == '@') { q1.push({i, j}); }
                if(table[i][j] == '*') { q2.push({i, j}); dist[i][j] = 0; }
            }
        }

        while(!q2.empty()) {
            auto [R,C] = q2.front(); q2.pop();
            for(int i = 0; i < 4; ++i) {
                int nr = R + dr[i];
                int nc = C + dc[i];
                if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
                if(table[nr][nc] == '#') continue;
                if(dist[nr][nc] != -1) continue;
                dist[nr][nc] = dist[R][C] + 1;
                q2.push({nr, nc});
            }
        }

        dist[q1.front().first][q1.front().second] = 0;
        bool flag = 0;

        while(!q1.empty()) {
            auto [R, C] = q1.front(); q1.pop();
            for(int i = 0; i < 4; ++i) {
                int nr = R + dr[i];
                int nc = C + dc[i];
                if(nr < 0 || nc < 0 || nr >= N || nc >= M) {
                    cout << dist[R][C] + 1 << endl;
                    queue<pair<int,int>>().swap(q1);
                    flag = 1;
                    break;
                }
                if(table[nr][nc] == '#') continue;
                if(dist[nr][nc] != -1 && dist[nr][nc] <= dist[R][C]+1) continue;
                dist[nr][nc] = dist[R][C] + 1;
                q1.push({nr, nc});

            }
        }
        if(!flag) cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
// std::queue<pair<int,int>>(std::move(q1));