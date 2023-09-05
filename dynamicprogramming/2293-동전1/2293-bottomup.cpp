#include <iostream>

using namespace std;

int N;
int K;
int seq[105];
int cache[10005];

int main(void) {
    cin >> N >> K;
    for(int i = 0; i < N; ++i) {
        cin >> seq[i];
    }

    cache[0] = 1;
    for(int i = 0; i < N; ++i) {
        for(int j = seq[i]; j <= K; ++j) {
            cache[j] += cache[j - seq[i]];
        }
    }

    cout << cache[K];

    return 0;
}