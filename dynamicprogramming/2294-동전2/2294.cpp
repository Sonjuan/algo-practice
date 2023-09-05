#include <iostream>
#include <algorithm>

using namespace std;

int coins[100];
int amount[10005];

int main(void) {
    int N;
    int K;

    cin >> N >> K;
    
    for(int i = 0; i < N; ++i) {
        cin >> coins[i];
    }

    fill(amount, amount+10005, 9999999);
    amount[0] = 0;

    for(int i = 1; i <= K; ++i) {
        for(int j = 0; j < N; ++j) {
            if(i - coins[j]>= 0) {
                amount[i] = min(amount[i], amount[i-coins[j]] +1);
            }
        }
    }
    
    if(amount[K] != 9999999) {
        cout << amount[K];
    }else {
        cout << -1;
    }

    return 0;
}
