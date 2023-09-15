#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<string> table(1005);
int N;
int M;
int distj[1005][1005];
int distf[1005][1005];

int dr[4] = {0, 0, -1, 1};
int dc[4] = {1,-1, 0, 0};

int main(void) {
    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        cin >> table[i];
    }

    queue<pair<int,int>> jq;
    queue<pair<int,int>> fq;
    
    for(int i = 0; i < N; ++i) {
        fill(distj[i], distj[i]+M, -1);
        fill(distf[i], distf[i]+M, -1);
    }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(table[i][j] == 'J') {
                jq.push({i, j});
                distj[i][j] = 0;
            }
            if(table[i][j] == 'F') {
                fq.push({i, j});
                distf[i][j] = 0;
            }
        }
    }

    while(!fq.empty()) {
        auto [r, c] = fq.front(); fq.pop();
        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if(table[nr][nc] == '#') continue;
            if(distf[nr][nc] != -1) continue;
            distf[nr][nc] = distf[r][c] + 1;
            fq.push({nr, nc});
        }
    }
    while(!jq.empty()) {
        auto [r, c] = jq.front(); jq.pop();
        for(int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nc < 0 || nr >= N || nc >= M) {
                cout << distj[r][c] + 1;
                return 0;
            }
            if(table[nr][nc] == '#') continue;
            if(distj[nr][nc] != -1) continue;

            // insight about this line
            if(distf[nr][nc] != -1 && distf[nr][nc] <= distj[r][c] + 1) continue;
            
            distj[nr][nc] = distj[r][c] + 1;
            jq.push({nr, nc});
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}