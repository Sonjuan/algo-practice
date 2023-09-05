#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[512];
vector<bool> vis(512);
int isTree;
int trees;

void dfs(int cur, int prev) {
    vis[cur] = true;
    for(int nxt : graph[cur]) {
        if(nxt == prev) continue;
        if(vis[nxt]) {
            isTree = 0;
            continue;
        }
        dfs(nxt, cur);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N = -1; int M = -1;
    int tc = 0;

    while(true) {
        cin >> N >> M;
        if(N == 0 && M == 0) break;

        fill(vis.begin(), vis.begin()+N+1, 0);
        for(int i = 1; i <= N; ++i)
            graph[i].clear();
        trees = 0;

        while(M--) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);    
        }

        
        for(int i = 1; i <= N; ++i) {
            if(vis[i]) continue;
            isTree = 1;
            dfs(i, -1);
            trees += isTree;
        }
        cout << "Case " << ++tc << ": ";

        if(!trees)          cout << "No trees." << '\n';
        else if(trees == 1) cout << "There is one tree." << '\n';
        else                cout << "A forest of " << trees << " trees." << '\n';
    }

    return 0;
}