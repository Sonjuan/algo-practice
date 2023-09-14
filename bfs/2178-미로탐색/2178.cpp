#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int N;
int M;
vector<string> table(102);

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int dist[102][102];

int bfs() {
    queue<pair<int,int>> q;
    q.push({0,0});
    for(int i = 0; i < N; ++i) {
        fill(dist[i], dist[i]+M, -1);
    }
    dist[0][0] = 1;
    while(!q.empty()) {
        auto [r, c] = q.front(); q.pop();

        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if(table[nr][nc] == '0') continue;
            if(dist[nr][nc] != -1) continue;

            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }

    return dist[N-1][M-1];
}


int main(void) {
    cin >> N >> M;  
    for(int i = 0; i < N; ++i) {
        cin >> table[i];
    }

    cout << bfs();

    return 0;
}