#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    vector<int> rounds(N, 0);
    vector<int> left(N), right(N);

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        left[i] = (i - 1 + N) % N;
        right[i] = (i + 1) % N;
    }

    queue<int> q;

    for (int i = 0; i < N; ++i) {
        if (a[left[i]] > a[i] && a[right[i]] > a[i]) {
            q.push(i);
        }
    }

    int round = 0;

    while (!q.empty() && N > 2) {
        ++round;
        int size = q.size();

        for (int i = 0; i < size; ++i) {
            int idx = q.front();
            q.pop();

            if (rounds[idx] != 0) continue;

            rounds[idx] = round;

            int l = left[idx];
            int r = right[idx];
            right[l] = r;
            left[r] = l;

            --N;

            if (a[left[l]] > a[l] && a[right[l]] > a[l] && rounds[l] == 0) {
                q.push(l);
            }
            if (a[left[r]] > a[r] && a[right[r]] > a[r] && rounds[r] == 0) {
                q.push(r);
            }
        }
    }

    for (int i = 0; i < rounds.size(); ++i) {
        cout << rounds[i] << " ";
    }
    cout << endl;

    return 0;
}