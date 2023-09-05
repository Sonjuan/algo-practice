#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    int N;
    int num;

    cin >> N;

    priority_queue<int, vector<int>, greater<>> pq;
    
    for(int i = 0; i < N * N; ++i) {
        cin >> num;
        pq.push(num);
        if(N < (int)pq.size()) pq.pop();
    }
    
    cout << pq.top() << endl;

    return 0;
}
