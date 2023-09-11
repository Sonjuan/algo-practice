#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[1000002];
int MaxLIS;

int main(void) {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;

        dp[temp] = dp[temp - 1] + 1;
        MaxLIS = max(MaxLIS, dp[temp]);
    }

    cout << N - MaxLIS;
    return 0;
}