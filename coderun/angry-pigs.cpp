#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main (void) {
    int N;
    cin >> N;

    unordered_set<int> birdsX;

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;

        birdsX.insert(x);
    }

    cout << birdsX.size() << endl;

    return 0;
}