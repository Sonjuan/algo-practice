// 우선순위 큐를 통한 구현

// 1. 임의의 정점을 선택해 최소 신장 트리에 추가
// 2. 최소 신장 트리에 포함된 정점과 최소 신장 트리에 포함되지 않은 정점을 연결하는 간선 중
// 비용이 가장 작은 것을 최소 신장 트리에 추가
// 3. 최소 신장 트리에 V-1개의 간선이 추가될 때까지 2번 과정을 반복


#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define X first
#define Y second

vector<pair<int, int>> adj[10005];
bool chk[10005];
int cnt = 0;

int v, e;

priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

int main(void) {
    cin >> v >> e;
    for(int i = 0; i < e; ++i) {
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
        adj[b].push_back({cost, a});
    }    

    int cnt = 0;
    int ans = 0;

    chk[1] = 1;
    for(auto nxt : adj[1]) {
        pq.push({nxt.X, 1, nxt.Y});
    }
    while(cnt < v-1) {
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if(chk[b]) continue;
        ans += cost;
        chk[b] = 1;
        cnt += 1;
        for(auto nxt : adj[b]) {
            if(!chk[nxt.Y])
                pq.push({nxt.X, b, nxt.Y});
        }
    }
    cout << ans;

    return 0;
}
