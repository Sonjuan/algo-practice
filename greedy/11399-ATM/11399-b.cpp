#include <iostream>
#include <algorithm>
using namespace std;


int N;
int seq[1002];

int main(void) {
    cin >> N;
    for(int i = 0 ; i < N ; ++i) {
        cin >> seq[i];
    }
    // Think carefully;
    sort(seq, seq+N);
    
    long long res = 0;
    for(int i = 0; i < N; ++i) {
        res += seq[i] * (N - i);
    }
    cout << res;
    return 0;
}