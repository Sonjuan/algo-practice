#include <iostream>
#include <algorithm>
using namespace std;

int N;
int X[10005];


int count(int j, int k) {
    int p = j, q = j;
    for(int a = N; a >= 1; a /= 2) {
        while(p+a < N && X[p+a] <  k) p += a;
        while(q+a < N && X[q+a] <= k) q += a;
    }
    return q-p;
}

int main(void) {
    cin >> N;

    for(int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    sort(X, X+N);
    
    long long ans = 0;
    for(int i = 0; i < N-1; ++i) {
        for(int j = i+1; j < N; ++j) {
            ans += count(j, -X[i]-X[j]);
        }
    }

    cout << ans;

    return 0;
}
