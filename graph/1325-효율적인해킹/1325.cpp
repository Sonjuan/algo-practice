#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int M;
vector<int> table[10002];
int vis[10002];
int score[10002];

void dfs(int u) {
    vis[u] = 1;
    for(int v : table[u]) {
        if(vis[v]) continue;
        score[v] += 1;
        dfs(v);
    }
}

int main(void) {
    cin >> N >> M;

    int u, v;
    for(int i = 0; i < M; ++i) {
        cin >> u >> v;
        table[u].push_back(v);
    }

    for(int i = 1; i <= N; ++i) {
        fill(vis, vis+10002, 0);
        dfs(i);
    }

    int MaxVal = *max_element(score+1, score+N+1);
    for(int i = 1; i <= N; ++i) {
        if(score[i] == MaxVal) {
            cout << i << " ";
        }
    }

    return 0;
}