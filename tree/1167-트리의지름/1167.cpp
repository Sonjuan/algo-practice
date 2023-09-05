#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> tree[100002];
vector<int> vis(100002);
int Max;
int MaxNode;

void dfs(int u, int dist) {
    vis[u] = true;
    if(dist > Max) {
        Max = dist;
        MaxNode = u;
    }
    for(auto [v, nxtDist] : tree[u]) {
        if(vis[v]) continue;
        dfs(v, dist + nxtDist);
    }
}

int main(void) {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        int node, child, dist;
        cin >> node;
        while(1) {
            cin >> child;
            if(child == -1) break;
            cin >> dist;
            tree[node].push_back({child, dist});
            tree[child].push_back({node, dist});
        }
    }

    dfs(1, 0);
    fill(vis.begin(), vis.begin()+100002, 0);
    dfs(MaxNode, 0);

    cout << Max;

    return 0;
}