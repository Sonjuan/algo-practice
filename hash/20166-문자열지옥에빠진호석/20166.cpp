#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int N;
int M;
int K;

string table[12];

int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1,  0,  1,-1, 1,-1, 0, 1};

unordered_map<string, int> cache;

void dfs(int i, int j, string s) {
    cache[s] += 1;
    if(s.size() == 5) return;
    for(int dir = 0; dir < 8; ++dir) {
        int nr = (i + dr[dir] + N) % N;
        int nc = (j + dc[dir] + M) % M;
        dfs(nr, nc, s+table[nr][nc]);
    }
}

int main(void) {
    cin >> N >> M >> K;
    for(int i = 0; i < N; ++i) {
        cin >> table[i];
    }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            dfs(i, j, string(1, table[i][j]));
        }
    }

    while(K--) {
        string query;
        cin >> query;
        cout << cache[query] << endl;
    }

    return 0;
}