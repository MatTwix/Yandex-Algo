#include <iostream>
#include <vector>

using namespace std;

int main (void) {
    int M = -1, buf, ans = -1;
    cin >> M;

    vector<int> capacities(31);

    for (auto i = 0; i < 31; i++) {
        cin >> buf;
        capacities[i] = (i == 0) ? buf : max(buf, capacities[i - 1] * 2);
        if (capacities[i] >= M) ans = (ans == -1) ? i : min(ans, i);
    }

    int j = ans - 1;
    ans = 1 << ans;
    int currSecs = capacities[j];
    int currPrice = 1 << j;

    for (auto i = j - 1; i >= 0; i--) {
        if (currSecs + capacities[i] >= M) {
            ans = min(ans, currPrice + (1 << i));
        } else {
            currSecs += capacities[i];
            currPrice += (1 << i);
        }
    }

    cout << ans;

    return 0;
}