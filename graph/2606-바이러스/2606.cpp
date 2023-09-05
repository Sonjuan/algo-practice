#include <iostream>

using namespace std;

int N;
int M;
int table[102][102];
int vis[102];
int ans;

void dfs(int u) {
    vis[u] = 1;
    for(int v = 0; v < 102; ++v) {
        if(vis[v]) continue;
        if(!table[u][v]) continue;
        ans++;
        dfs(v);
    }
}

int main(void) {
    cin >> N >> M;
    for(int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        table[u][v] = 1;
        table[v][u] = 1;
    }
    dfs(1);

    cout << ans;

    return 0;
}