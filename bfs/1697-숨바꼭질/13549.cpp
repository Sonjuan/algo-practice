#include <iostream>
#include <queue>

using namespace std;

int N;
int K;
int dp[200002];

int main(void) {
    cin >> N >> K;

    fill(dp, dp+200002, -1);
    dp[N] = 0;

    queue<int> q;
    q.push(N);

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        vector<int> moves = {cur-1, cur+1, cur*2};

        for(auto move : moves) {
            if(move < 0 || move > 200002 || dp[move] != -1) continue;
            dp[move] = dp[cur] + 1;
            q.push(move);
        }
    }

    cout << dp[K];

    return 0;
}