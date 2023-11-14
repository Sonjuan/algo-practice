#include <iostream>
#include <queue>
#include <string>

using namespace std;

int dr[4] = {0, 0, -1, 1};
int dc[4] = {1,-1, 0, 0};

int T;
int H;
int W;
string inputkeys;
char board[120][120];
int vis[120][120];

int main(void) {
    cin >> T;
    while(T--) {
        cin >> H >> W;
        queue<pair<int,int>> q;
        queue<pair<int,int>> door[26];
        int keys[26] = {};
        int cnt = 0;
        for(int i = 0; i <= H+1; i++) {
            fill(vis[i], vis[i]+W+2, 0);
            fill(board[i], board[i]+W+2, 0);
        }
        for(int i = 1; i <= H; ++i) {
            for(int j = 1; j <= W; ++j) {
                cin >> board[i][j];
            }
        }
        cin >> inputkeys;
        for(int i = 0; i < inputkeys.size(); ++i) {
            keys[inputkeys[i] - 'a'] = 1;
        }
        q.push({0,0});
        vis[0][0] = 1;
        while(!q.empty()) {
            auto [R, C] = q.front(); q.pop();
            for(int dir = 0; dir < 4; ++dir) {
                int nr = R + dr[dir];
                int nc = C + dc[dir];
                if(nr < 0 || nc < 0 || nr > H+1 || nc > W+1) continue;
                if(vis[nr][nc] || board[nr][nc] == '*') continue;
                vis[nr][nc] = 1;

                if(board[nr][nc] >= 'a' && board[nr][nc] <= 'z') {
                    int k = board[nr][nc] - 'a';
                    keys[k] = 1;
                    while(!door[k].empty()) {
                        auto ndoor = door[k].front(); door[k].pop();
                        q.push({ndoor.first, ndoor.second});
                    }
                } else if(board[nr][nc] >= 'A' && board[nr][nc] <= 'Z') {
                    int k = board[nr][nc] + 32 - 'a';
                    if(!keys[k]) {
                        door[k].push({nr,nc});
                        continue;
                    }
                } else if(board[nr][nc] == '$') cnt++;
                q.push({nr,nc});
            }
        }
        cout << cnt << endl;
    }

    return 0;
}