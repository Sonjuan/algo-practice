#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
string graph[30];
vector<int> ans;
int vis[30][30];
int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};

int main(void) {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> graph[i];
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(graph[i][j] == '0') continue;
            if(vis[i][j]) continue;
            int count = 1;
            queue<pair<int,int>> q;
            q.push({i, j});
            vis[i][j] = 1;
            while(!q.empty()) {
                auto [R, C] = q.front(); q.pop();
                for(int dir = 0; dir < 4; ++dir) {
                    int nr = R + dr[dir];
                    int nc = C + dc[dir];
                    if(nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
                    if(graph[nr][nc] == '0') continue;
                    if(vis[nr][nc]) continue;
                    vis[nr][nc] = 1;
                    count += 1;
                    q.push({nr, nc});
                }
            }
            ans.push_back(count);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i : ans) cout << i << endl;
    return 0;
}