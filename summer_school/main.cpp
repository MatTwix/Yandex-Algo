#include <iostream>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    long long need = 3 * a + b - c;
    if (need <= 0) {
        cout << 0 << endl;
    } else {
        cout << (need + 2) / 3 << endl;
    }

    return 0;
}