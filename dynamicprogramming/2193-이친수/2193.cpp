#include <iostream>

using namespace std;

int main(void) {
    long long dp[100];
    dp[1] = 1;
    dp[2] = 1;

    for(int i = 3; i < 100; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    int N;
    cin >> N;
    cout << dp[N];

    return 0;
}

// 수가 늘어나는 방식은 
// 0 -> 1,0  1 -> 0
// 두가지로 볼 수 있다.
// 1000 1001 1010
// 100 101
// 10

// 10 고정
// 뒤에 i-2 i-1 의 부분 문자열이 붙는다
