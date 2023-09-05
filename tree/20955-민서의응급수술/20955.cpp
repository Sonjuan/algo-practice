#include <iostream>
#include <vector>

using namespace std;

int N;
int M;

vector<int> graph[100002];
vector<bool> vis(100002);



void dfs(int u) {
    vis[u] = true;
    for(int v : graph[u]) {
        if(vis[v]) continue;
        dfs(v);
    }
}

int main(void) {
    cin >> N >> M;
    for(int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int bond = -1;
    for(int i = 1; i <= N; ++i) {
        if(vis[i]) continue;
        bond++;
        dfs(i);
    }    
    cout << (bond) + (bond+M) - (N - 1);    

    return 0;
}