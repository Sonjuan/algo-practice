#include <iostream>

using namespace std;

int N;
int M;
int cut;
int graph[100002];

int find(int x) {
    if(graph[x] < 0) return x;
    return graph[x] = find(graph[x]);
}

void try_merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) {
        cut++;
        return;
    }
    if(graph[u] > graph[v]) swap(u, v);
    graph[u] += graph[v];
    graph[v] = u;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    fill(graph, graph+N+1,-1);

    for(int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        try_merge(u, v);
    }    
    // (cut) + (N-1) - (M-cut)
    // cout << N - M - 1 + 2 * cut;
    // for(int i = 0; i <= N; ++i) {
    //     cout << graph[i] << " ";
    // }

    return 0;
}