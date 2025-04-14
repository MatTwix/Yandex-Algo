#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int groupCount, classCount;
    cin >> groupCount >> classCount;

    vector<pair<int, int>> groupSizes(groupCount);
    vector<pair<int, int>> classCapacities(classCount);

    for (int idx = 0; idx < groupCount; ++idx) {
        cin >> groupSizes[idx].first;
        groupSizes[idx].second = idx + 1;
    }

    for (int idx = 0; idx < classCount; ++idx) {
        cin >> classCapacities[idx].first;
        classCapacities[idx].second = idx + 1;
    }

    sort(groupSizes.begin(), groupSizes.end());
    sort(classCapacities.begin(), classCapacities.end());

    vector<int> assignedClass(groupCount + 1, 0);
    int groupIndex = 0, classIndex = 0, totalAssigned = 0;

    while (groupIndex < groupCount && classIndex < classCount) {
        if (classCapacities[classIndex].first > groupSizes[groupIndex].first) {
            int groupId = groupSizes[groupIndex].second;
            int classId = classCapacities[classIndex].second;
            assignedClass[groupId] = classId;
            ++totalAssigned;
            ++groupIndex;
            ++classIndex;
        } else {
            ++classIndex;
        }
    }

    cout << totalAssigned << endl;
    for (int i = 1; i <= groupCount; ++i) {
        cout << assignedClass[i] << " ";
    }
    cout << endl;

    return 0;
}