#include <iostream>

using namespace std;

int main (void) {
    long long N;
    cin >> N;

    long long cnt = 0;

    while (N != 0) {
        if ((N & 1) == 1) cnt++;
        N >>= 1;
    }

    cout << cnt;
}