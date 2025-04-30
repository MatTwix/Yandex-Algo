#include <iostream>
#include <unordered_set>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main (void) {
    unordered_set<int> firstSet, secondSet;
    string line;

    getline(cin, line);
    stringstream ss1(line);
    int num;
    while (ss1 >> num) {
        firstSet.insert(num);
    }

    getline(cin, line);
    stringstream ss2(line);
    while (ss2 >> num) {
        secondSet.insert(num);
    }

    vector<int> intersection;

    for (auto& el : firstSet) {
        if (secondSet.find(el) != secondSet.end()) {
            intersection.push_back(el);
        }
    }

    stable_sort(intersection.begin(), intersection.end());

    for (auto& el : intersection) {
        cout << el << " ";
    }

    return 0;
}