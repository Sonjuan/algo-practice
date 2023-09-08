#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int K;
int M;
vector<int> graph[102002];
vector<int> dist(102002);

int main(void) {
    cin >> N >> K >> M;
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < K; ++j) {
            int temp;
            cin >> temp;
            graph[100002+i].push_back(temp);
            graph[temp].push_back(100002+i);
        }
    }

    queue<int> q;
    q.push(1);
    
    fill(dist.begin(), dist.begin()+102002, -1);
    dist[1] = 0;

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(cur == N) break;

        for(auto v : graph[cur]) {
            if(dist[v] != -1) continue;
            
            dist[v] = dist[cur] + 1;
            q.push(v);
        }
    }
    
    if(dist[N] == -1) cout << -1;
    else cout << dist[N] / 2 + 1;

    return 0;
}