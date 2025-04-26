#include <iostream>
#include <vector>

using namespace std;

int main (void) {
    int N;
    cin >> N;

    int repeats = 0;
    while ((1 << repeats) < N) repeats++;

    int res = N, buf = N, lDig;
    for (int i = 0; i < repeats; ++i) {
        lDig = 1 & buf;
        buf >>= 1;
        buf |= lDig << (repeats - 1);
        res = max(res, buf);
    }

    cout << res;
}