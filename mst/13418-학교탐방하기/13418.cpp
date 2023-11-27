#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

int N;
int M;

vector<tuple<int,int,int>> table1;
vector<tuple<int,int,int>> table2;
vector<int> p(1005, -1);
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
bool is_diff_group(int u, int v) {
    u = find(u); v = find(v);
    if(u==v) return 0;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}
int main(void) {
    cin >> N >> M;
    for(int i = 0; i <= M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        table1.push_back({!w,u,v});
        table2.push_back({!w,u,v});
    }
    sort(table1.begin(), table1.end(), greater<tuple<int,int,int>>());
    sort(table2.begin(), table2.end());

    int cnt1 = 0;
    int ans1 = 0;
    for(int i = 0; i < table1.size(); ++i) {
        auto [w, a, b] = table1[i];
        if(!is_diff_group(a, b)) continue;
        ans1 += w;
        cnt1++;
        if(cnt1 == N) break;
    }

    p = vector<int>(1005, -1);
    int cnt2 = 0;
    int ans2 = 0;
    for(int i = 0; i < table2.size(); ++i) {
        auto [w, a, b] = table2[i];
        if(!is_diff_group(a, b)) continue;
        ans2 += w;
        cnt2++;
        if(cnt2 == N) break;
    }
    cout << ans1*ans1 - ans2 * ans2;
    return 0;
}