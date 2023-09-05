#include <iostream>

using namespace std;

int dp[1001][11];

int main(void) {
    int N;
    cin >> N;
    
    for(int i = 0; i <=10; ++i) {
        dp[1][i] = i;
    }
    

    for(int i = 2; i <= N; ++i) {
        for(int j = 1; j <= 10; ++j) {
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % 10007;
        }
    }
    
    
    cout << dp[N][10];

    return 0;
}
