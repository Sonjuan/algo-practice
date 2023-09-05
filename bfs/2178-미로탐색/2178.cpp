#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
#define X first
#define Y second
string board[102];
int dist[102][102];
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1,0, 0};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i <n; ++i) {
        cin >> board[i];
    }
    for(int i = 0; i < n; ++i)  fill(dist[i], dist[i]+m, -1);


    return 0;
}