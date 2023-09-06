#include <iostream>
#include <map>

using namespace std;

int N;
map<long long, int> table;

int Max = 0;
long long ans;

int main(void) {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        long long num;
        cin >> num;

        if(table.find(num) == table.end()) 
            table[num] = 1;
        else    
            table[num]++;

        if(table[num] > Max) 
            Max = table[num];
    }

    for(auto i : table) {
        if(i.second == Max) {
            cout << i.first;
            break;
        }
    }

    return 0;
}