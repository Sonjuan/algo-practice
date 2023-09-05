#include <iostream>

using namespace std;

int T;
int N;
int M;
int coins[22];
int cache[10002];

void dp() {
    cache[0] = 1;
    for(int i = 0; i < N; ++i) {
        for(int j = coins[i]; j <= M; ++j) {
            cache[j] += cache[j - coins[i]];
        }
    }
}

int main(void) {
    cin >> T;
    while(T--) {
        cin >> N;
        for(int i = 0; i < N; ++i) {
            cin >> coins[i];
        }
        cin >> M;
        fill(cache, cache+10002, 0);
        dp();
        cout << cache[M] << '\n';
    }

    return 0;
}