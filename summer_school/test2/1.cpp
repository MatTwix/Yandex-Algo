#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main (void) { 
    int N;
    cin >> N;

    unordered_map<string, pair<int, int>> addresses;
    
    string buf, address;
    for (size_t i = 0; i < N; ++i) {
        cin >> address;
        cin >> buf;

        address += " " + buf;
        if (addresses.find(address) != addresses.end()) addresses[address].second++;
        else addresses[address] = {0, 1};

        cin >> address;
        cin >> buf;

        address += " " + buf;
        if (addresses.find(address) != addresses.end()) addresses[address].first++;
        else addresses[address] = {1, 0};
    }

    int entanceCnt = 0, exitCnt = 0;
    string entance, exit;

    for (const auto address : addresses) {
       if (address.second.first < address.second.second) {
        entanceCnt++;
        if (entanceCnt > 1) {
            cout << -1;
            return 0;
        }
        entance = address.first;
       } else if (address.second.first > address.second.second) {
        exitCnt++;
        if (exitCnt > 1) {
            cout << -1;
            return 0;
        }
        exit = address.first;
       }
    }   

    if (entance == "" || exit == "") cout << -1;
    else cout << entance << " " << exit;

    return 0;
}