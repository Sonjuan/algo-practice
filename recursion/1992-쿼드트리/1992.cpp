#include <iostream>
#include <vector>
using namespace std;

int arr[64][64];

void solution(int N, int r, int c) {
    if(N == 1) {
        cout << arr[r][c];
        return;
    }

    int zero = 1;
    int one = 1;
    for(int i = 0; i < r+N; ++i) {
        for(int j = 0; j < c+N; ++j) {
            if(arr[i][j] == 1) {
                zero = 0;
            }else {
                one = 0;
            }
        }
    }

    if(zero) {
        cout << 0;
    }else if(one) {
        cout << 1;
    }else {
        cout << "(";
        solution(N / 2, r, c);
        solution(N / 2, r, c+N/2);
        solution(N / 2, r+N/2, c);
        solution(N / 2, r+N/2, c+N/2);
        cout << ")";
    }
    return;
}

int main(void) {
    int N;
    cin >> N;

    for(int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        for(int j = 0; j < N; ++j) {
            arr[i][j] = str[j] - '0';
        }
    }
    solution(N, 0, 0);

    return 0;
}