#include <iostream>
#include <vector>

using namespace std;

int N;
int D;
int K;
int C;

vector<int> sushi(3002);
vector<int> belt(30002*2);
int Kind;
int Max;

void inc(int u) {
    if(!sushi[u]) {
        Kind++;
        Max = max(Max, Kind);
    }
    sushi[u]++;
}

void del(int u) {
    sushi[u]--;
    if(!sushi[u]) {
        Kind--;
    }
}

int main(void) {
    cin >> N >> D >> K >> C;
    for(int i = 0; i < N; ++i) {
        cin >> belt[i];
        belt[i+N] = belt[i];
    }
    sushi[C]++;
    Kind = 1;
    Max = 1;

    for(int i = 0; i < N * 2; ++i) {
        if(i >= K) del(belt[i-K]);
        inc(belt[i]);
    }

    cout << Max;

    return 0;
}