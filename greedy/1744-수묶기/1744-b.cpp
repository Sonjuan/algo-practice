#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int res;

int main(void) {
    cin >> N;
    vector<int> plus;
    vector<int> neg;

    for(int i =0; i < N; ++i) {
        int temp;
        cin >> temp;    
        if(temp == 1)  res++;
        else if(temp > 0) {
            plus.push_back(temp);
        }else {
            neg.push_back(temp);
        }
    }

    sort(plus.begin(), plus.end());
    sort(neg.begin(), neg.end(), greater<int>());

    while(plus.size() > 1) {
        res += (*(plus.end()-1)) * (*(plus.end()-2));
        plus.pop_back();
        plus.pop_back();
    }
    if(plus.size()) res += plus[0];

    while(neg.size() > 1) {
        res += (*(neg.end()-1)) * (*(neg.end()-2));
        neg.pop_back();
        neg.pop_back();
    }
    if(neg.size()) res += neg[0];

    cout << res;

    return 0;
}