#include <iostream>

using namespace std;

int N;
int seq[102];

int main(void) {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> seq[i];
    }

    int ans = 0;
    for(int i = N-1; i >= 1; --i) {
        if(seq[i] <= seq[i-1]) {
            ans += seq[i-1] - seq[i] +1;
            seq[i-1] = seq[i] - 1;
        }
    }

    cout << ans;
    return 0;
}