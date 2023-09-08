#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int M;
vector<int> graph[20002];
vector<int> dist(20002);
vector<int> vis(20002);
int Max;

void bfs(int u) {
    vis[u] = 1;
    dist[u] = 0;

    queue<int> q;
    q.push(u);
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();

        for(auto v : graph[cur]) {
            if(vis[v]) continue;
            vis[v] = 1;
            dist[v] = dist[cur] + 1;
            if(dist[v] > Max) Max = dist[v];
            q.push(v);
        }
    }
}

int main(void) {
    cin >> N >> M;
    for(int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(1);
    
    vector<int> ans;
    for(int i = 1; i <= N; ++i)
        if(dist[i] == Max) 
            ans.push_back(i);
    
    cout << ans[0] << " " << dist[ans[0]] << " " << ans.size();
    return 0;
}