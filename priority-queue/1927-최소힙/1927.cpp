#include <bits/stdc++.h>

using namespace std;

int N;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    int temp;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < N; ++i) {
        cin >> temp;

        if(temp) {
            pq.push(temp);
        }else {
            if(pq.empty()) {
                cout << "0\n";
            }else {
                cout << pq.top() << '\n';
                pq.pop();
            }
            
        }
    }


    return 0;
}
