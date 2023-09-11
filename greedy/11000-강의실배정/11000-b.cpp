#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
pair<int, int> lec[200002];
priority_queue<int, vector<int>, greater<>> pq;

int main(void) {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        lec[i] = {a, b};
    }

    sort(lec, lec+N);
    pq.push(0);

    for(int i = 0; i < N; ++i) {
        int cur = pq.top();
        int st = lec[i].first; 
        int en = lec[i].second;

        pq.pop();

        if(st < cur) pq.push(cur);
        pq.push(en);
    }

    cout << pq.size();

    return 0;
}