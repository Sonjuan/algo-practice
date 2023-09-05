#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> tree[10'002];
vector<int> vis(10002);
int N;
int Max;
int MaxNode;

void dfs(int u, int dist) {
    if(dist > Max) {
        Max = dist;
        MaxNode = u;
    }
    vis[u] = true;
    for(auto [v, nxtDist] : tree[u]) {
        if(vis[v]) continue;
        dfs(v, dist + nxtDist);
    }
}

int main(void) {
    cin >> N;
    for(int i = 0; i < N-1; ++i) {
        int parent, child, dist;
        cin >> parent >> child >> dist;
        tree[parent].push_back({child, dist});
        tree[child].push_back({parent, dist});
    }

    dfs(1, 0);
    fill(vis.begin(), vis.begin()+10002, 0);
    dfs(MaxNode, 0);

    cout << Max;

    return 0;
}