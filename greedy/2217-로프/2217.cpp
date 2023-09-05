#include <iostream>
#include <algorithm>

using namespace std;

int N;
int seq[100'002];

int main(void) {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> seq[i];
    }
    sort(seq, seq+N);

    int Max = 0;
    for(int i = 1; i <= N; i++) {
        Max = max(Max, seq[N-i]*i);
    }

    cout << Max;
    return 0;
}