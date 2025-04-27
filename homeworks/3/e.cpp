#include <iostream>

using namespace std;

int main() {
    long long x1, y, x2, c;
    cin >> x1 >> y >> x2 >> c;
    cout << (x1 ^ y) << endl << (x2 ^ y) << endl;

    return 0;
}