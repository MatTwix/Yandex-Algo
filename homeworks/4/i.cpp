#include <iostream>
#include <vector>

using namespace std;

int main (void) {
    int N;
    cin >> N;

    long long resMass = 0;

    vector<long long> mass(N + 1, 0);
    vector<long long> prev(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        int a, b;
        cin >> a >> b;

        if (b == 0) {
            mass[i] = mass[prev[a]];
            prev[i] = prev[prev[a]];
        } else {
            mass[i] = mass[a] + b;
            prev[i] = a;
        }

        resMass += mass[i];
    }

    cout << resMass << endl;

    return 0;
}