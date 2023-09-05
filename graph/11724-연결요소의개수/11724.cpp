#include <iostream>

using namespace std;

int N;
int M;
int graph[1005][1005];
int visited[1005];
int ans;

void dfs(int u) {
    visited[u] = 1;
    for(int i = 1; i <= 1000; ++i) {
        if(visited[i] || graph[u][i] == 0) continue;
        dfs(i);
    }
}

int main(void) {
    cin >> N >> M;

    while(M--) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for(int i = 1; i <= N; ++i) {
        if(visited[i]) continue;
        ans++;
        dfs(i);
    }

    cout << ans;

    return 0;
}