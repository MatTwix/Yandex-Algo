#include <iostream>
#include <unordered_set>

using namespace std;

int main (void) {
    unordered_set<int> differentNumbers;

    int num;
    while (cin >> num) { 
        differentNumbers.insert(num);
    }

    cout << differentNumbers.size() << endl;

    return 0;
}