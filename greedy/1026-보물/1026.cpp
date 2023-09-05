#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arrA[52];
int arrB[52];

int main(void) {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> arrA[i];
    }
    for(int i = 0; i < N; ++i) {
        cin >> arrB[i];
    }

    sort(arrA, arrA+N);
    sort(arrB, arrB+N, std::greater<int>());

    int S = 0;
    for(int i = 0; i < N; ++i) {
        S += arrA[i]*arrB[i];
    }
    
    cout << S;

    return 0;
}