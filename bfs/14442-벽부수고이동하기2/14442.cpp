#include <iostream>
#include <queue>
#include <string>
#include <tuple>
using namespace std;

int N;
int M;
int K;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, -1, 1};

string graph[1002];
int dist[1002][1002][12];

int main(void) {
    cin >> N >> M >> K;
    for(int i = 0; i < N; ++i) {
        cin >> graph[i];
    }
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});
    dist[0][0][0] = 1;
    while(!q.empty()) {
        auto [R,C,B] = q.front();q.pop();
        if(R == N-1 && C == M-1) {
            cout << dist[R][C][B] << endl;
            return 0;
        }
        for(int dir = 0; dir < 4; ++dir) {
            int nr = R + dr[dir];
            int nc = C + dc[dir];
            int nb = B;
            if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if(graph[nr][nc] == '1') nb += 1;
            if(nb > K || dist[nr][nc][nb] > 0) continue;
            dist[nr][nc][nb] = dist[R][C][B]+1;
            q.push({nr,nc,nb});

        }
    }
    cout << -1;

    return 0;
}