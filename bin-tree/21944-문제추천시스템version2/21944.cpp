#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

string op;
int G, N, L, P, x;
pair<int, int> probinfo[100'002];
map<int, map<int, set<int>>> probDB;
void insertDB(int P, int L, int G) {
    probinfo[P] = {G, L};
    if (probDB.find(G) == probDB.end()) 
        probDB.insert({G, map<int, set<int>>()});
    if (probDB[G].find(L) == probDB[G].end())
        probDB[G].insert({L, set<int>()});
    probDB[G][L].insert(P);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while (N--) {
        cin >> P >> L >> G;
        insertDB(P, L, G);
    }

    cin >> N;
    while(N--) {
        cin >> op;
        if(op == "recommend") {
            cin >> G >> x;
            if(x == 1) 
                cout << *(probDB[G].rbegin()->second.rbegin()) << '\n';
            else
                cout << *(probDB[G].begin()->second.begin()) << '\n';
        }else if(op == "recommend2") {
            cin >> x;
            pair<int, int> mxv = {0, -1};
            pair<int, int> mnv = {102, 100'002};            
            for(auto &group : probDB) {
                if(x == 1) {
                    auto gMxLevKV = group.second.rbegin();
                    pair<int, int> gv = {gMxLevKV->first, *gMxLevKV->second.rbegin()};
                    mxv = max(mxv, gv);
                }else {
                    auto gMnLevKV = group.second.begin();
                    pair<int, int> gv = {gMnLevKV->first, *gMnLevKV->second.begin()};
                    mnv = min(mnv, gv);
                }
            }
            cout << (x == 1 ? mxv.second : mnv.second) << '\n';

        }else if(op == "recommend3") {
            cin >> x >> L;
            pair<int, int> mxv = {0, -1};
            pair<int, int> mnv = {102, 100'002};
            for(auto &group : probDB) {
                for(auto &level : group.second) {
                    if(x == 1) {
                        if (level.first < L) continue;
                        pair<int, int> lv = {level.first, *level.second.begin()};
                        if (lv < mnv) mnv = lv;
                    }else {
                        if (L <= level.first) continue;
                        pair<int, int> lv = {level.first, *level.second.rbegin()};
                        if (mxv < lv) mxv = lv;
                    }
                }
            }
            if(x == 1) 
                cout << (mnv.first == 102 ? -1 : mnv.second) << '\n';
            else
                cout << (mxv.first == 0 ? -1 : mxv.second) << '\n';
        
        }else if(op == "add") {
            cin >> P >> L >> G;
            insertDB(P, L, G);

        }else if(op == "solved") {
            cin >> P;
            auto [G, L] = probinfo[P];
            probDB[G][L].erase(P);
            if(probDB[G][L].empty()) probDB[G].erase(L);
            if(probDB[G].empty()) probDB.erase(G);
        }
    }
    return 0;
}
