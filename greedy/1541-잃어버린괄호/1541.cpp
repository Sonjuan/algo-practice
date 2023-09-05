#include <iostream>
#include <string>

using namespace std;

string query;

int main(void) {
    cin >> query;

    int sign = 1;
    int num = 0;
    int res = 0;

    for(int i = 0; i < query.size(); ++i) {
        if(query[i] != '+' && query[i] != '-') {
            num *= 10;
            num += query[i] - '0';            
        }else {
            res += num * sign;
            if(query[i] == '-')
                sign = -1;
            num = 0;
        }
    }

    cout << res + (num*sign);
    return 0;
}