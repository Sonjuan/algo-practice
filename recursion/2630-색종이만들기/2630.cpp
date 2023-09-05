#include <bits/stdc++.h>
using namespace std;

int paper[128][128];
int ans[2];

bool check(int n, int x, int y) {
    for(int i = x; i < x+n; ++i) {
        for(int j = y; j < y+n; ++j) {
            if(paper[i][j] != paper[x][y]) return false;
        }
    }
    return true;
}

void func(int n, int x, int y) {
    if(check(n, x, y)) {
        ans[paper[x][y]] += 1;
        return;
    }
    n = n >> 1;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; ++j) {
            func(n, x+i*n, y+j*n);
        }
    }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) 
        cin >> paper[i][j];
  func(n, 0, 0);
  for (int i = 0; i < 2; i++) cout << ans[i] << '\n';
}