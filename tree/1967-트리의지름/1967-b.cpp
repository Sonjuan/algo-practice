#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> tree[10002];
int N;
int Max;

int dfs(int u) {
    vector<int> dist;
    int first = 0;
    int second = 0;

    for(auto [v, d] : tree[u]) {
        int dist = dfs(v) + d;
        if(dist > first) {
            second = first;
            first = dist;
        }else if(dist > second) {
            second = dist;
        }
    }
    Max = max(Max, first + second);
    return first;
}

int main(void) {
    cin >> N;
    for(int i = 0; i < N-1; ++i) {
        int parent, child, dist;
        cin >> parent >> child >> dist;
        tree[parent].push_back({child, dist});
    }
    dfs(1);
    cout << Max;
    return 0;
}