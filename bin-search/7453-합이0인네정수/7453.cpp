#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[4002], B[4002], C[4002], D[4002];
int AB[16000002], CD[16000002];

int count(int K) {
    int p = -1;
    int q = -1;

    for(int a = N*N; a >= 1; a /= 2) {
        while(p+a < N*N && CD[p+a] < K) p += a;
        while(q+a < N*N && CD[q+a]<= K) q += a;
    }

    return q-p;
}

int main(void) {
    cin >> N;

    for(int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            AB[i*N + j] = A[i] + B[j];
        }
    }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            CD[i*N +j] = C[i] + D[j];
        }
    }

    sort(AB, AB + N*N);
    sort(CD, CD + N*N);

    long long ans = 0;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            ans += count(-AB[i*N + j]);
        }
    }
    
    cout << ans;
    return 0;
}
