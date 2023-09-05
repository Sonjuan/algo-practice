#include <iostream>

using namespace std;

int N;
int K;
int seq[10];
int cnt;

int main(void) {
    cin >> N >> K;
    for(int i = 0; i < N; ++i) {
        cin >> seq[i];
    }

    int i = N-1;
    while(i >= 0) {
        if(K >= seq[i]) {
            cnt++;
            K -= seq[i];
        }else {
            i--;
        }
    }

    cout << cnt;

    return 0;
}