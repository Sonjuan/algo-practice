#include <iostream>
#include <vector>

using namespace std;

int N;
int M;
vector<int> tree[100002];
vector<int> score(100002);

void dfs(int u) {
    for(int v : tree[u]) {
        score[v] += score[u];
        dfs(v);
    }
}

int main(void) {
    cin >> N >> M;

    for(int i = 1; i <= N; ++i) {
        int parent;
        cin >> parent;
        if(parent == -1) continue;
        tree[parent].push_back(i);
    }

    for(int i = 0; i < M; ++i) {
        int u, point;
        cin >> u >> point;
        score[u] += point;
    }

    dfs(1);

    for(int i = 1; i <= N; ++i) {
        cout << score[i] << " ";
    }

    return 0;
}