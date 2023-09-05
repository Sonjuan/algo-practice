#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> graph[1002];
int N;
int M;

int main(void) {
    cin >> N >> M;

    for(int i = 0; i < N-1; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }
    
    while(M--) {
        int src, dst;
        cin >> src >> dst;
        queue<pair<int, int>> q;
        vector<bool> vis(1002);
        
        q.push({src, 0});
        vis[src] = true;
        while(!q.empty()) {
            auto [cur, dist] = q.front(); q.pop();
            if(cur == dst) {
                cout << dist << endl;
                break;
            }
            for(auto [nxt, nxtDist] : graph[cur]) {
                if(vis[nxt]) continue;
                vis[nxt] = true;
                q.push({nxt, dist + nxtDist});
            }
        }
    }

    return 0;
}