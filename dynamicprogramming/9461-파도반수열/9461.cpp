#include <iostream>

using namespace std;

int main(void) {
    long long dp[101];
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    for(int i = 6; i < 101; ++i) {
        dp[i] = dp[i-1] + dp[i-5];
    }
    
    int N;
    cin >> N;
    
    while(N--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }


    return 0;
}
