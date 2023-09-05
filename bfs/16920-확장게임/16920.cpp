#include <bits/stdc++.h>
using namespace std;

int canExtended[1000][1000];
int step[10];
int area[10];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<tuple<int, int, int>> q[10];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, P;
    cin >> N >> M >> P;

    for(int i = 1; i <= P; ++i) {
        cin >> step[i];
    }
    char ch;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> ch;
            if(ch == '.') canExtended[i][j] = 1;
            else if(ch == '#') canExtended[i][j] = 0;
            else {
                canExtended[i][j] = 0;
                q[ch - '0'].push({i, j, 0});
                area[ch - '0'] += 1;
            }
        }
    }

    while(1) {
        bool isExtend = 0;
        for(int i = 1; i <= P; ++i) {
            queue<tuple<int, int, int>> nextq;
            while(!q[i].empty()) {
                int curx, cury, curstep;
                tie(curx, cury, curstep) = q[i].front();
                q[i].pop();
                if(curstep >= step[i]) {
                    nextq.push({curx, cury, 0});
                    continue;
                }
                for(int dir = 0; dir < 4; ++dir) {
                    int x = curx + dx[dir], y = cury + dy[dir];
                    if(x < 0 || x >= N || y < 0 || y >= M) continue;
                    if(!canExtended[x][y]) continue;
                    q[i].push({x, y, curstep+1});
                    canExtended[x][y] = 0;
                    area[i]++;
                    isExtend = 1;
                }
            }
            q[i] = nextq;
        }
        if(!isExtend) break;
    }

    for(int i = 1; i <= P; ++i) {
        cout << area[i] << " ";
    }


    return 0;
}