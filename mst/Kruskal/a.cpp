// 사이클을 만들어내지 않는 선에서 비용이 작은 간선부터 최소 신장 트리에 편입시키는 
// 그리디 알고리즘이다.

// 같은 그룹에 있는 두 정점을 연결하는 간선을 골랐을 때 해당 간선을 최소 신장 트리에 넣지 않는 이유는 해당 간선으로
// 인해 사이클이 생기기 때문이다.

// 간선의 정렬에서 ElogE A와 B가 같은 그룹인지(Flood Fill의 경우 O(V))
//     Union Find의 경우 O(아커만 역함수 coursera 참조)
//     O(ElogE)

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<int> p(10005, -1);

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return 0;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u; // important point in Rank
    else p[u] = v;
    return 1; 
}

int v, e;
tuple<int, int, int> edge[100005];

int main(void) { 
    cin >> v >> e;
    for(int i = 0; i < e; ++i) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }
    sort(edge, edge + e);
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < e; ++i) {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if(!is_diff_group(a,b)) continue;
        ans += cost;
        cnt++;
        if(cnt == v-1) break;
    }
    cout << ans;
    return 0;
}