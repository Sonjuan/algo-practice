#include <iostream>
#include <vector>

using namespace std;

int N;
int K;
vector<int> seq(1'000'005);
int Max;

int main(void) {
    cin >> N >> K;
    for(int i = 0; i < N; ++i) {
        cin >> seq[i];
    }

    int cnt = 0;
    int st = 0;
    int en = 1;

    if(seq[st] % 2 == 1) cnt++;

    for(; st < N; ++st) {
        while(en < N && cnt + seq[en] % 2 <= K) {
            cnt += seq[en] % 2;
            en++;
        }
        Max = max(Max, en - st - cnt);
        cnt -= seq[st] % 2;
    }
    cout << Max;
    return 0;
}