#include <iostream>
#include <vector>

using namespace std;

int K;
int V;
int E;

vector<int> graph[20002];
vector<int> vis(20002);
vector<int> color(20002);
int flag;

void dfs(int u, int c) {
    vis[u] = 1;
    color[u] = c;

    for(auto v : graph[u]) {
        if(vis[v] && color[v] == c) flag = 1;
        if(vis[v]) continue;
        dfs(v, 1-c);
    }
}

bool check() {
    for(int i = 1; i <= V; ++i) {
        if(vis[i]) continue;
        dfs(i, 0);
    }
    if(flag) return false;
    else     return true;
}

int main(void) {
    cin >> K;
    while(K--) {
        cin >> V >> E;

        for(int i = 1; i <= V; ++i) {
            graph[i].clear();
        }
        fill(vis.begin(), vis.begin()+20002, 0);
        fill(color.begin(), color.begin()+20002, 0);
        flag = 0;

        for(int i = 0; i < E; ++i) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }       
        if(check()) cout << "YES" << endl;
        else        cout << "NO"  << endl;
    }
    return 0;
}