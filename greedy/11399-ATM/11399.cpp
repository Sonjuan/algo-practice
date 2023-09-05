#include <iostream>
#include <algorithm>

using namespace std;

int N;
int seq[1002];

int main(void) {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> seq[i];
    }

    sort(seq, seq+N);

    for(int i = 1; i < N; ++i) {
        seq[i] += seq[i-1];
    }

    long long res = 0;
    for(int i = 0; i < N; ++i) {
        res += seq[i];
    }
    cout << res;

    return 0;
}