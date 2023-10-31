#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int N;
vector<int> link(1005, -1);
vector<tuple<long long,int,int>> edge;

int find(int x) {
    if(link[x] < 0) return x;
    return link[x] = find(link[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return 0;
    if(link[u] == link[v]) link[u] -= 1;
    if(link[u] < link[v]) link[v] = u;
    else link[u] = v;
    return 1;
}

int main(void) {
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            long long w;
            cin >> w;
            if(i >= j) continue;
            edge.push_back({w, i, j});
        }
    }
    std::sort(edge.begin(), edge.end());
    long long ans = 0;
    int cnt = 0;
    for(int i = 0; i < edge.size(); ++i) {
        auto [w, a, b] = edge[i];
        if(!is_diff_group(a, b)) continue;
        ans += w;
        cnt += 1;
        if(cnt == N-1) break;
    }

    cout << ans;

    return 0;
}