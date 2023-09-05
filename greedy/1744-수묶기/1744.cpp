#include <iostream>
#include <algorithm>

using namespace std;

int N;
int zero;

int main(void) {
    vector<int> plus;
    vector<int> minus;
    cin >> N;
    for(int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        if(temp == 0) {
            zero++;
            continue;
        }else if(temp > 0) {
            plus.push_back(temp);
        }else {
            minus.push_back(temp);
        }
    }

    sort(plus.begin(), plus.end(), std::greater<int>());
    sort(minus.begin(), minus.end());
    int res = 0;
    int rep = 0;
    int rem = 0;

    if(plus.size() % 2) {
        rep = plus.back();
        plus.pop_back();
    }
    if(minus.size() % 2) {
        rem = minus.back();
        minus.pop_back();
    }

    for(int i = 0; i < minus.size(); i += 2) {
        res += minus[i] * minus[i+1];
    }

    if(zero > 0 && rem != 0) rem = 0;

    for(int i = 0; i < plus.size(); i += 2) {
        if(plus[i] == 1 || plus[i+1] == 1) res += plus[i] + plus[i+1];
        else                               res += plus[i] * plus[i+1];
    }
    cout << res + rep + rem << endl;
    // cout << res << " " << rep << " " << rem << endl;

    return 0;
}