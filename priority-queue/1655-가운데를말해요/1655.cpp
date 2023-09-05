#include <iostream>
#include <queue>

using namespace std;

int N;

int main(void) {
    cin >> N;

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;

    int t;
    for(int i = 0; i < N; ++i) {
        cin >> t;
        if(maxHeap.size() <= minHeap.size()) {
            maxHeap.push(t);
        }else {
            minHeap.push(t);
        }

        if(!minHeap.empty() && minHeap.top() < maxHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        cout << maxHeap.top() << endl;
    }


    return 0;
}
