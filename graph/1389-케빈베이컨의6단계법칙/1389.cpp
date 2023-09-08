#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

int N;
int M;
vector<int> graph[102];
vector<int> dist(102);

int bfs(int u) {
    queue<int> q;
    q.push(u);

    fill(dist.begin(), dist.begin()+102, -1);
    dist[u] = 0;

    while(!q.empty()) {
        int cur = q.front(); q.pop();

        for(auto v : graph[cur]) {
            if(dist[v] != -1) continue;
            dist[v] = dist[cur] + 1;
            q.push(v);
        }
    }
    return accumulate(dist.begin()+1, dist.begin()+N+1, 0);
}

int main(void) {
    cin >> N >> M;
    for(int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int Min = INT32_MAX;
    int ans = 0;
    
    for(int i = 1; i <= N; ++i) {
        int sum = bfs(i);
        if(Min > sum) {
            Min = sum;
            ans = i;
        }
    }

    cout << ans;

    return 0;
}