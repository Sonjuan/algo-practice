#include <iostream>
#include <unordered_map>

using namespace std;

int N;
int M;
unordered_map<string, string> table;

int main(void) {
    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        string ID;
        string PASS;
        cin >> ID >> PASS;
        table[ID] = PASS;
    }

    for(int i = 0; i < M; ++i) {
        string query;
        cin >> query;
        cout << table[query] << '\n';
    }


    return 0;
}