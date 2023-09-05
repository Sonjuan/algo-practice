#include <iostream>

using namespace std;

int N;
int a[2010], d[2010][2010];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    for(int i = 1; i <= N; ++i) cin >> a[i];

    for(int i = 1; i <= N; ++i) {
        d[i][i] = 1;

        if(a[i-1] == a[i]) {
            d[i-1][i] = 1;
        }
    }
   
    for(int gap = 2; gap < N; ++gap) {
        for(int i = 1; i <= N - gap; ++i) {
            int s = i, e = i + gap;
            if(a[s] == a[e] && d[s+1][e-1]) {
                d[s][e] = 1;
            }
        }
    }

    int M;
    cin >> M;

    while(M--) {
        int start, end;
        cin >> start >> end;
        
        cout << d[start][end] << '\n';
    }

    return 0;
}
