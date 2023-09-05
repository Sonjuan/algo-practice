#include <iostream>

using namespace std;

int N;
int M;
int G;
int R;
int Max;

int table[51][51];

int main(void) {
    cin >> N >> M >> G >> R;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M ;++j) {
            cin >> table[i][j];
        }
    }

    

    return 0;
}