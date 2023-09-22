#include <iostream>
#include <queue>
using namespace std;

int T;
int L;
int dist[305][305];
queue<pair<int, int>> q;
int tarR, tarC;

int dr[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dc[8] = {-2, -1,  1,  2, 2, 1,-1,-2};

int bfs() {
    while(!q.empty()) {
        auto [R, C] = q.front(); q.pop();
        for(int i = 0; i < 8; ++i) {
            int nr = R + dr[i];
            int nc = C + dc[i];
            if(nr < 0 || nc < 0 || nr >= L || nc >= L) continue;
            if(dist[nr][nc] != -1) continue;

            dist[nr][nc] = dist[R][C] + 1;
            if(nr == tarR && nc == tarC) {
                return dist[nr][nc];
            }
            q.push({nr, nc});
        }
    }
    return dist[tarR][tarC];
}

int main(void) {
    cin >> T;
    while(T--) {
        cin >> L;
        q = queue<pair<int,int>>();
        for(int i = 0; i < 305; ++i) {
            fill(dist[i], dist[i]+305, -1);
        }

        int curR, curC;
        cin >> curR >> curC;
        q.push({curR, curC});
        dist[curR][curC] = 0;

        cin >> tarR >> tarC;

        if(curR == tarR && curC == tarC) {
            cout << dist[curR][curC] << endl;
            continue;
        }

        cout << bfs() << endl;
    }

    return 0;
}