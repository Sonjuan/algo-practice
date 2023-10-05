#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int N;
int graph[105][105];
int vis[105][105];
int vis2[105][105];
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int main(void) {
    cin >> N;
    for(int i = 0; i < N; ++i)
        for(int j = 0 ; j < N; ++j)
            cin >> graph[i][j];

    for(int i = 0; i < 105; ++i)
        fill(vis[i], vis[i]+105, -1);

    int id = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(graph[i][j] == 0 || vis[i][j] != -1) continue;
            queue<pair<int,int>> q;
            q.push({i,j});
            vis[i][j] = id;
            while(!q.empty()) {
                auto [R, C] = q.front();q.pop();
                for(int dir = 0; dir< 4; ++dir) {
                    int nr = R + dr[dir];
                    int nc = C + dc[dir];
                    if(nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
                    if(graph[nr][nc] == 0) continue;
                    if(vis[nr][nc] != -1) continue;
                    q.push({nr,nc});
                    vis[nr][nc] = id;
                }
            }
            id += 1;
        }
    }

    int ans = 500;

    for(int k = 0; k < id; ++k) {
        queue<tuple<int,int,int>> q;
        for(int i = 0; i < 105; ++i)
            fill(vis2[i], vis2[i]+105, -1);

        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if(vis[i][j] == k) {
                    q.push({i,j,0});
                    vis2[i][j] = 0;
                }
            }
        }

        while(!q.empty()) {
            auto [R,C,D] = q.front(); q.pop();
            if(graph[R][C] != 0 && k != vis[R][C]) ans = min(ans, D-1);

            for(int dir = 0; dir < 4; ++dir) {
                int nr = R + dr[dir];
                int nc = C + dc[dir];
                int nd = D + 1;

                if(nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
                if(vis2[nr][nc] != -1) continue;
                
                q.push({nr,nc,nd});
                vis2[nr][nc] = 0;
            }
        }
    }

    cout << ans;

    return 0;
}