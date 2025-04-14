#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int testCount;
    cin >> testCount;

    const int INF = std::numeric_limits<int>::max();
    int remaining = INF;

    if (testCount == 0) {
        cout << 0;
        return 0;
    }

    vector<vector<int>> allTests(testCount);
    for (int t = 0; t < testCount; ++t) {
        int elementsCount;
        cin >> elementsCount;
        allTests[t].resize(elementsCount);
        for (int i = 0; i < elementsCount; ++i) {
            cin >> allTests[t][i];
        }
    }

    for (const auto& testData : allTests) {
        if (testData.empty()) {
            cout << 0 << endl << 0 << endl;
            continue;
        }

        if (testData.size() == 1) {
            cout << 1 << endl << 1 << endl;
            continue;
        }

        vector<vector<int>> groups;
        vector<int> tempGroup;
        remaining = INF;

        for (int value : testData) {
            if (remaining < 1) {
                groups.push_back(tempGroup);
                tempGroup.clear();
                remaining = 1000;
            }

            if (tempGroup.empty()) {
                tempGroup.push_back(value);
                remaining = value - 1;
                continue;
            }

            if (value > static_cast<int>(tempGroup.size())) {
                tempGroup.push_back(value);
                remaining = min(remaining - 1, value - static_cast<int>(tempGroup.size()));
            } else {
                groups.push_back(tempGroup);
                tempGroup.clear();
                tempGroup.push_back(value);
                remaining = value - 1;
            }
        }

        if (!tempGroup.empty()) {
            groups.push_back(tempGroup);
        }

        cout << groups.size() << endl;
        for (const auto& group : groups) {
            cout << group.size() << " ";
        }
        cout << endl;
    }

    return 0;
}