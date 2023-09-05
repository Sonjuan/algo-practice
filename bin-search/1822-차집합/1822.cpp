#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int M;

int main(void) {
    cin >> N >> M;
    vector<int> Ntable;
    vector<int> Mtable;
    
    int temp;
    for(int i = 0; i < N; ++i) {
        cin >> temp;
        Ntable.push_back(temp);
    }
    for(int i = 0; i < M; ++i) {
        cin >> temp;
        Mtable.push_back(temp);
    }
    
    sort(Ntable.begin(), Ntable.end());
    sort(Mtable.begin(), Mtable.end());
    
    vector<int> ans;

    for(int i = 0; i < N; ++i) {
        
        int p = 0;
        for(int a = M; a >= 1; a /= 2) {
            while(a+p < M && Mtable[a+p] <= Ntable[i]) {
                p += a;
            }
        }

        if(Mtable[p] != Ntable[i]) {
            ans.push_back(Ntable[i]);
        }

    }
    
    if(ans.size() == 0) {
        cout << 0;
    }else {
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
    }
    return 0;
}
