#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int N;
int M;
int K;
string graph[1002];
int vis[1002][1002][12][2];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

queue<tuple<int,int,int,int>> q;

int main(void) {
    cin >> N >> M >> K;
    for(int i = 0; i < N; ++i) {
        cin >> graph[i];
    }
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            for(int k = 0; k < 12; ++k)
                for(int d = 0; d < 2; ++d)
                    vis[i][j][k][d] = -1;

    q.push({0,0,0,0});
    vis[0][0][0][0] = 1;

    while(!q.empty()) {
        auto [R,C,B,D] = q.front(); q.pop();
        if(R == N-1 && C == M-1) {
            cout << vis[R][C][B][D];
            return 0;
        }
        for(int dir = 0; dir < 4; ++dir) {
            int nr = R + dr[dir];
            int nc = C + dc[dir];
            int nb = B;
            int nd = 1 - D;
            if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if(nd == 0 && graph[nr][nc] == '1') {
                if(vis[R][C][B][nd] != -1) continue;
                vis[R][C][B][nd] = vis[R][C][B][D] + 1;
                q.push({R,C,B,nd});
                continue;
            }
            if(graph[nr][nc] == '1') nb += 1;
            if(nb > K) continue;
            if(vis[nr][nc][nb][nd] != -1) continue;
            vis[nr][nc][nb][nd] = vis[R][C][B][D] + 1;
            q.push({nr,nc,nb,nd});
        }
    }

    cout << -1;

    return 0;
}