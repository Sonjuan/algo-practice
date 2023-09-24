#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N;
int M;
int H;

int table[105][105][105];
int dist[105][105][105];
int dr[6] = {0, 0, 1, -1, 0, 0};
int dc[6] = {0, 0, 0,  0,-1, 1};
int dh[6] = {1, -1, 0,  0, 0, 0};

queue<tuple<int,int,int>> q;

int ans;

int main(void) {
    cin >> M >> N >> H;
    fill_n(&dist[0][0][0], 105* 105 * 105, -1);

    int allflag = 0;
    for(int k = 0; k < H; ++k) {
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                cin >> table[k][i][j];
                if(table[k][i][j] == 1) {
                    q.push({k, i, j});
                    dist[k][i][j] = 0;
                }
                if(table[k][i][j] == 0)
                    allflag = 1;
            }
        }
    }

    if(allflag = 0) {
        cout << 0 << endl;
        return 0;
    }

    while(!q.empty()) {
        auto [K, R, C] = q.front(); q.pop();
        for(int i = 0; i < 6; ++i) {
            int nh = K + dh[i];
            int nr = R + dr[i];
            int nc = C + dc[i];
            if(nr < 0 || nc < 0 || nh < 0 || nr >=N || nc >= M || nh >= H) continue;
            if(table[nh][nr][nc] == -1) continue;
            if(dist[nh][nr][nc] != -1) continue;
            dist[nh][nr][nc] = dist[K][R][C] + 1;
            ans = max(ans, dist[nh][nr][nc]);
            q.push({nh, nr, nc});
        }
    }

    int flag = 0;
    for(int k = 0; k < H; ++k) {
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(table[k][i][j] == 0 && dist[k][i][j] == -1) {
                    flag = 1;
                }
            }
        }
    }

    if(flag) {
        cout << -1 << endl;
    }else {
        cout << ans << endl;
    }

    return 0;
}