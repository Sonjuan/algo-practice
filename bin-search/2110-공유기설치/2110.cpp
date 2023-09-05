#include <iostream>
#include <algorithm>

using namespace std;

int N;
int C;

int X[200002];

int main(void) {
    cin >> N >> C;

    for(int i = 0; i < N; ++i) {
        cin >> X[i];
    }

    sort(X, X + N);
    
    int start = 1;
    int end = X[N-1] - X[0];
    
    int ans = 0;

    while(start <= end) {
        int router = 1;
        int mid = start + (end - start) /2;
        int st = X[0];

        for(int i = 1; i < N; ++i) {
            if(X[i] - st >= mid) {
                router++;
                st = X[i];
            }
        }

        if(router >= C) {
            ans = max(ans, mid);
            start = mid + 1;
        }else {
            end = mid - 1;
        }

    }
       
    cout << ans;

    return 0;
}
