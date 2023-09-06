#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int M;
vector<int> grapha[102];
vector<int> graphb[102];
int vis[102];
int ans;

bool bfs(int u, vector<int> (&graph) [102]) {
    fill(vis, vis+102, 0);
    queue<int> q;

    q.push(u);
    vis[u] = 1;

    int cnt = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int v : graph[cur]) {
            if(vis[v]) continue;
            q.push(v);
            vis[v] = 1;
            cnt++;
        }
    }
    return cnt >= (N+1)/2;
}

int main(void) {
    cin >> N >> M;

    for(int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        grapha[a].push_back(b);
        graphb[b].push_back(a);
    }

    for(int i = 1; i <= N; ++i) {
        if(bfs(i, grapha) || bfs(i, graphb))
            ans++;
    }
    
    cout << ans;

    return 0;
}