#include <iostream>
#include <vector>

using namespace std;

int N;
int M;
int Truth[150];
int ans;

vector<int> graph[150];

void dfs(int u) {
    for(int v : graph[u]) {
        if(Truth[v]) continue;
        Truth[v] = 1;
        dfs(v);
    }
}

int main(void) {
    cin >> N >> M;
    
    int t;
    cin >> t;
    while(t--) {
        int temp;
        cin >> temp;
        Truth[temp] = 1;
    }

    for(int i = 0; i < M; ++i) {
        int t;
        cin >> t;
        while(t--) {
            int p;
            cin >> p;
            graph[52+i].push_back(p);
            graph[p].push_back(52+i);
        }
    }

    for(int i = 1; i <= N; ++i) {
        if(Truth[i]) dfs(i);
    }

    for(int i = 52; i < 52+M; ++i) {
        if(Truth[i] == 0) ans++;
    }

    cout << ans;
    return 0;
}