#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int R;
int Q;
int subTreeSize[100002];

vector<bool> vis(100002, false);
vector<int> tree[100002];

int countSubtreeNode(int cur) {
    vis[cur] = true;
    for(int v : tree[cur]) {
        if(vis[v]) continue;
        subTreeSize[cur] += countSubtreeNode(v);
    }    
    subTreeSize[cur]++;
    return subTreeSize[cur];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> R >> Q;


    for(int i = 0; i < N-1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    countSubtreeNode(R);
    
    while(Q--) {
        int q;
        cin >> q;
        cout << subTreeSize[q] << '\n';
    }
    return 0;
}