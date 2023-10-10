#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int K;
int W; // col
int H; // row
int graph[205][205];
int vis[205][205][31];

int dr[12] = {0, 0, -1, 1, -1, -2, -2, -1, 1, 2,  2,  1};
int dc[12] = {1, -1, 0, 0, -2, -1,  1,  2, 2, 1, -1, -2};

int main(void) {
    cin >> K >> W >> H;
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            cin >> graph[i][j];
            for(int k = 0; k < 31; k++) {
                vis[i][j][k] = -1;
            }
        }
    }

    queue<tuple<int,int,int>> q;
    q.push({0, 0, 0});
    vis[0][0][0] = 0;

    while(!q.empty()) {
        auto [R, C, step] = q.front(); q.pop();

        if(R == H-1 && C == W-1) {
            cout << vis[R][C][step];
            return 0;
        }

        if(step < K) {
            for(int i = 4; i < 12; ++i) {
                int nr = R + dr[i];
                int nc = C + dc[i];
                int ns = step + 1;
                if(nr < 0 || nc < 0 || nr >= H || nc >= W) continue;
                if(graph[nr][nc] == 1) continue;
                if(vis[nr][nc][ns] != -1) continue;
                q.push({nr,nc,ns});
                vis[nr][nc][ns] = vis[R][C][step] + 1;
            }
        }

        for(int i = 0; i < 4; ++i) {
            int nr = R + dr[i];
            int nc = C + dc[i];
            int ns = step;
            if(nr < 0 || nc < 0 || nr >= H || nc >= W) continue;
            if(graph[nr][nc] == 1) continue;
            if(vis[nr][nc][ns] != -1) continue;
            q.push({nr,nc,ns});
            vis[nr][nc][ns] = vis[R][C][step] + 1;
        }
    }

    cout << -1;
    return 0;
}