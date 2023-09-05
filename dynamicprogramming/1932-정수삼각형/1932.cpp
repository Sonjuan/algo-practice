#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int N;
    cin >> N;

    int board[501][501];

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j <= i; ++j) {
            cin >> board[i][j];
        }
    }

    vector<int> d1(501, 0);
    d1[0] = board[0][0];

    for(int i = 1; i < N; ++i) {
        vector<int> d2(501, 0);
        for(int j = 0; j <= i; ++j) {
            d2[j]   = max(d2[j],   d1[j]+board[i][j]);
            d2[j+1] = max(d2[j+1], d1[j]+board[i][j+1]);
        }
        d1 = d2;
    }

    cout << *max_element(d1.begin(), d1.end());

    return 0;
}
