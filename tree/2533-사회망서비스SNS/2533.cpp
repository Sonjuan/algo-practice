#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> tree[1000002];
vector<bool> vis(1000002);

int bipartite(int u, int color) {
    int res = 0;
    if(color == 1) res++;
    color = 1 - color;

    vis[u] = true;
    for(int v : tree[u]) {
        if(vis[v]) continue;
        res += bipartite(v, color);
    }

    return res;
}

int main(void) {
    cin >> N;
    for(int i = 0; i < N-1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int a = bipartite(1, 0);
    fill(vis.begin(), vis.begin()+N+1, false);
    int b = bipartite(1, 1);
    
    cout << a << b;
    cout << (a > b ? b : a);

    return 0;
}