#include <iostream>
#include <queue>

using namespace std;

int N;
int M;
int V;

int table[1002][1002];
int visA[1002];
int visB[1002];

void dfs(int u) {
    cout << u << " ";
    visA[u] = 1;
    for(int v = 0; v < 1002; ++v) {
        if(visA[v]) continue;
        if(!table[u][v]) continue; 
        dfs(v);
    }
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    visB[u] = 1;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        cout << v << " ";
        for(int i = 0; i < 1002; ++i) {
            if(visB[i]) continue;
            if(!table[v][i]) continue;
            visB[i] = 1;
            q.push(i);
        }
    }
}

int main(void) {
    cin >> N >> M >> V;

    for(int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        table[u][v] = 1;
        table[v][u] = 1;
    }

    dfs(V);
    cout << endl;
    bfs(V);

    return 0;
}