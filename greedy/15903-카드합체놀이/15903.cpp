#include <iostream>
#include <queue>

using namespace std;

int N;
int M;
priority_queue<long long,vector<long long>, greater<long long>> pq;

int main(void) {
    cin >> N >> M;

    for(int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    while(M--) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        long long c = a + b;
        pq.push(c);
        pq.push(c);
    }

    long long ans = 0;
    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans;

    return 0;
}