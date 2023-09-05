#include <iostream>
#include <algorithm>

using namespace std;

int N;
int M;
int table[1000000];

int main(void) {
    cin >> N >> M;

    for(int i = 0; i < M; ++i) {
        cin >> table[i];
    }
    sort(table, table+M);

    int st = 0;
    int en = table[M-1];
    
    while(st < en) {
        int mid = (st+en+1) / 2 ;
        long long cnt = 0;
        int k = lower_bound(table, table+M, mid) - table;

        for(int i = k; i < M; ++i) {
            cnt += table[i] / mid;
        }

        if(cnt >= N) {
            st = mid;
        }else {
            en = mid-1;
        }
    }
    
    cout << st << endl;

    return 0;
}
