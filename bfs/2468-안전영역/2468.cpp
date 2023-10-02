#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int water;

int graph[105][105];
int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};

int main(void) {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> graph[i][j];
            if(water < graph[i][j]) water = graph[i][j];
        }
    }

    vector<int> ans;
    while(water--) {
        int count = 0;
        queue<pair<int,int>> q;
        int copy[105][105];
        std::copy(&graph[0][0], &graph[0][0]+105*105, &copy[0][0]);

        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if(copy[i][j] <= water) continue;
                count += 1;
                q.push({i, j});
                copy[i][j] = 0;

                while(!q.empty()) {
                    auto [R, C] = q.front();q.pop();
                    for(int dir = 0; dir < 4; ++dir) {
                        int nr = R + dr[dir];
                        int nc = C + dc[dir];
                        if(nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
                        if(copy[nr][nc] == 0) continue;
                        if(copy[nr][nc] <= water) continue;
                        copy[nr][nc] = 0;
                        q.push({nr, nc});
                    }
                }

            }
        }
        ans.push_back(count);
    }
    cout << *max_element(ans.begin(), ans.end());
    return 0;
}