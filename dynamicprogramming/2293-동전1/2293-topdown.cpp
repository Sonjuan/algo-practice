#include <iostream>

using namespace std;

int N;
int K;
int seq[105];
int cache[10005][105];

int dp(int k, int pos) {
    if(k == 0) return 1;
    if(cache[k][pos] != -1) return cache[k][pos];
    int res = 0;
    for(int i = pos; i < N; ++i) {
        if(k - seq[i] >= 0){
            res += dp(k-seq[i], i);
        }
    }
    cache[k][pos] = res;
    return res;
}

int main(void) {
    cin >> N >> K;
    for(int i = 0; i < N; ++i) {
        cin >> seq[i];
    }
    for(int i = 0; i <= K; ++i) {
        for(int j = 0; j <= N; ++j) {
            cache[i][j] = -1;
        }
    }
    cout << dp(K, 0);
    return 0;
}