#include <iostream>
#include <algorithm>

using namespace std;

int N;
int M;
int L;

int v[50];

bool solve(int x) {
    int must_cnt = 0;
    int pre = 0;
    for(int i = 0; i <= N; ++i) {
        int dist = v[i] - pre;

        if(dist >= x) {
            if(dist % x != 0) {
                must_cnt += dist / x;
            }else {
                must_cnt += (dist / x -1);
            }
        }
        pre = v[i];
    }

    if(must_cnt > M)
        return true;
    else
        return false;
}

int main(void) {
    cin >> N >> M >> L;
    
    for(int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    
    sort(v, v+N);
    v[N] = L;

    int st = 1, en = L;
    while(st < en) { 
        int mid = (st + en) / 2;
        if(solve(mid)) st = mid + 1;
        else en = mid;
    }

    cout << st;    

    return 0;
}
