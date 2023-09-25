#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int M;
int K;

int table[105][105];
int vis[105][105];

int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};

int main(void) {
    cin >> N >> M >> K;
    while(K--) {
        int a, b, c ,d;
        cin >> a >> b >> c >> d;
        for(int i = b; i < d; ++i) {
            for(int j = a; j < c; j++) {
                table[i][j] = 1;
            }
        }
    }
    
    int count = 0;
    vector<int> ans;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(table[i][j] == 1 || vis[i][j] == 1) continue;
            queue<pair<int,int>> q;
            int size = 1;
            
            q.push({i, j});
            vis[i][j] = 1;
            count++;
            while(!q.empty()) {
                auto [R, C] = q.front(); q.pop();
                for(int i = 0;i < 4; ++i) {
                    int nr = R + dr[i];
                    int nc = C + dc[i];
                    if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
                    if(table[nr][nc] == 1 || vis[nr][nc] == 1) continue;
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                    size++;
                }
            }
            ans.push_back(size);
        }
    }
    sort(ans.begin(), ans.end());

    cout << count << endl;
    for(int i : ans) cout << i << " ";

    return 0;
}
