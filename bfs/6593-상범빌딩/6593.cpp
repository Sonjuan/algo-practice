#include <iostream>
#include <queue>
#include <tuple>
#include <string>
using namespace std;

int L;
int R;
int C;

int dl[6] = {0, 0, 0, 0,  1, -1};
int dr[6] = {1, -1, 0, 0, 0, 0};
int dc[6] = {0, 0, -1, 1, 0, 0};

int main(void) {
    while(true) {
        cin >> L >> R >> C;
        if(L == 0 && R == 0 && C == 0) break;
        string graph[32][32];
        for(int i = 0; i < L; ++i) {
            for(int j = 0; j < R; ++j) {
                cin >> graph[i][j];
            }
        }
        queue<tuple<int,int,int>> q;
        int vis[32][32][32];

        for(int i = 0; i < L; ++i) {
            for(int j = 0; j < R; ++j) {
                for(int k = 0; k < C; ++k) {
                    vis[i][j][k] = -1;
                    if(graph[i][j][k] == 'S') {
                        q.push({i,j,k});
                        vis[i][j][k] = 0;
                    }
                }
            }
        }

        int flag = 0;
        while(!q.empty() && flag == 0) {
            auto [l,r,c] = q.front();q.pop();
            for(int dir = 0; dir < 6; ++dir) {
                int nl = l + dl[dir];
                int nr = r + dr[dir];
                int nc = c + dc[dir];


                if(nl < 0 || nr < 0 || nc < 0 || nl >= L || nr >= R || nc >= C) continue;
                if(graph[nl][nr][nc] == '#') continue;
                if(vis[nl][nr][nc] != -1) continue;
                if(graph[nl][nr][nc] == 'E') {
                    //       Escaped in      11                    minute(s).
                    cout << "Escaped in " << vis[l][r][c] + 1 << " minute(s)." << '\n';
                    flag = 1;
                    break;
                }
                q.push({nl,nr,nc});
                vis[nl][nr][nc] = vis[l][r][c] + 1;
            }
        }
        if(!flag) cout << "Trapped!" << '\n';
    }
    return 0;
}