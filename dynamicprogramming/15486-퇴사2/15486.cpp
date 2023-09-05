#include <iostream>
#include <vector>

using namespace std;

#define X first
#define Y second

int main(void) {
    int N;
    cin >> N;
        
    vector<pair<int,int>> arr(N+1, {0,0});

    for(int i = 1; i < N+1; ++i) {
        int time;
        int pay;
        cin >> time >> pay;
        arr[i] = {time, pay};
    }
    
    vector<int> dp(N+2, 0);
    for(int i = N; i >= 1; --i) {
        if(arr[i].X + i <= N+1) {
            dp[i] = max(arr[i].Y + dp[i+arr[i].X], dp[i+1]);           
        }else {
            dp[i] = dp[i+1];
        }
    }
    
    cout << dp[1];

    return 0;
}
