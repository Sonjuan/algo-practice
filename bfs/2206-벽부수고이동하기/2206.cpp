#include <iostream>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

int N;
int M;
string table[1005];
int dist[1005][1005][2];

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int main(void) {
    cin >> N >> M;
    for(int i = 0 ; i < N ;  ++i) cin >> table[i];
    for(int i = 0; i < 1005; ++i) {
        for(int j = 0; j < 1005; ++j) {
            for(int k = 0; k < 2; ++k) {
                dist[i][j][k] = -1;
            }
        }
    }

    queue<tuple<int,int,int>> q;
    q.push({0,0,0});

    dist[0][0][0] = 1;

    while(!q.empty()) {
        auto [R,C,B] = q.front();q.pop();
        if(R == N-1 && C == M-1) {
            cout << dist[R][C][B] << '\n';
            return 0;
        }
        for(int i = 0; i < 4; ++i) {
            int nr = R + dr[i];
            int nc = C + dc[i];
            int nb = B;

            if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if(table[nr][nc] == '1' && nb == 1) continue;
            if(dist[nr][nc][nb] != -1) continue;

            if(table[nr][nc] == '1') nb = 1;
            dist[nr][nc][nb] = dist[R][C][B] + 1;
            q.push({nr, nc, nb});
        }
    }   
    cout << -1 << '\n';
    return 0;
}