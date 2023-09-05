#include <iostream>
#include <queue>
using namespace std;

int N;
int M;
int table[502][502];
int vis[502];
int ans;

void dfs(int u, int dep) {
    for(int v = 0; v < 502; ++v) {
        if(!table[u][v]) continue;
        vis[v] = 1;
        if(dep == 1) continue;
        dfs(v, dep+1);
    }
}

int main(void) {
    cin >> N >> M;
    for(int i = 0; i< M; ++i) {
        int u, v;
        cin >> u >> v;
        table[u][v] = 1;
        table[v][u] = 1;
    }

    dfs(1,0);

    for(int i = 0; i <= N; ++i)
        if(vis[i]) ans++;
    
    cout << (ans == 0 ? 0 : ans-1);

    return 0;
}