#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> graph[1000002];
vector<int> tree[1000002];
vector<int> state[1000002];

void make_tree(int u, int prev) {
    for(int v : graph[u]) {
        if(v == prev) continue;
        tree[u].push_back(v);
        make_tree(v, u);
    }
}

int dp(int u, int color) {
    if(state[u][color] != -1) return state[u][color];
    int val = 0;
    if(color) {
        for(int v : tree[u]) {
            val += min(dp(v, 0), dp(v, 1));
        }
    }else {
        for(int v : tree[u]) {
            val += dp(v, 1);
        }
    }
    return state[u][color] = val + color;
}

int main(void) {
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        state[i].push_back(-1);
        state[i].push_back(-1);
    }
    for(int i = 0; i < N-1; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    make_tree(1, -1);
    
    cout << min(dp(1, 0), dp(1, 1));

    return 0;
}