#include <iostream>
#include <vector>

using namespace std;

int N;
int Max;

void backtrack(vector<int> weight, vector<int> du, int idx, int count) {
    if(idx == N) {
        if(Max < count) Max = count;        
        return;
    }

    if(du[idx] <= 0 || count == N-1) {
        backtrack(weight, du, idx+1, count);
        return ;
    }
    for(int i = 0; i < N; ++i) {
        if(i == idx) continue;
        if(du[i] <= 0) continue;
            
        int srcw = weight[idx];
        int destw = weight[i];

        du[idx] -= destw;
        du[i]   -= srcw;

        int sb = 0;
        int db = 0;

        if(du[idx] <= 0) {
            count += 1;
            sb = 1;
        }
        if(du[i] <= 0) {
            count += 1;
            db = 1;
        }

        backtrack(weight, du, idx+1, count);

        du[idx] += destw;
        du[i]   += srcw;

        if(sb == 1 && du[idx] > 0) {
            count -= 1;
        }
        if(db == 1 && du[i] > 0) {
            count -= 1;
        }
    }
}

int main(void) {
    cin >> N;
    Max = 0;
    vector<int> weight(N, 0);
    vector<int> du(N, 0);
    for(int i = 0; i < N; ++i) {
        cin >> du[i];
        cin >> weight[i];
    }
    backtrack(weight, du, 0,0);

    cout << Max;
    return 0;
}
