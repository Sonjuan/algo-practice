#include <iostream>
#include <vector>
using namespace std;

int N;
int table[102][102];

void dfs(int u, vector<int>& vis) {
    for(int v = 0; v < N; ++v) {
        if(!table[u][v]) continue;
        if(vis[v]) continue;
        vis[v] = 1;
        dfs(v, vis);
    }
}

int main(void) {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> table[i][j];
        }
    }

    for(int i = 0; i < N; ++i) {
        vector<int> vis(N, 0);
        dfs(i, vis);
        for(int k = 0; k < N; ++k) {
            cout << vis[k] << " ";
        }
        cout << endl;
    }


    return 0;
}