#include <iostream>
#include <vector>

using namespace std;

void modify (vector<long long>& tree, long long delta, long long i, long long N) {
    while (i <= N) {
        tree[i] += delta;
        i |= (i + 1);
    }
}

void build (vector<long long>& tree, vector<long long> arr, long long N) {
    for (long long i = 0; i < N; ++i) {
        modify(tree, arr[i], i, N);
    }
}

void set (vector<long long>& tree, vector<long long>& arr, long long i, long long val, long long N) {
    long long delta = val - arr[i];
    arr[i] = val;
    modify(tree, delta, i, N);
}

long long prefixSum (const vector<long long>& tree, long long i) {
    long long res = 0;
    while (i >= 0) {
        res += tree[i];
        i = (i & (i + 1)) - 1;
    }

    return res;
}

long long segmentSum (const vector<long long>& tree, long long start, long long end) {
    return prefixSum(tree, end) - prefixSum(tree, start - 1);
}

int main (void) {
    long long N;
    cin >> N;

    vector<long long> nums (N, 0);
    vector<long long> FenwickTree (N);

    build(FenwickTree, nums, N);

    long long K;
    cin >> K;

    vector<long long> ans;

    char type;
    long long buf1, buf2;
    for (long long i = 0; i < K; ++i) {
        cin >> type >> buf1 >> buf2;

        if (type == 'A') set(FenwickTree, nums, buf1 - 1, buf2, N);
        else ans.push_back(segmentSum(FenwickTree, buf1 - 1, buf2 - 1));
    }

    for (auto el : ans) cout << el << endl;

    return 0;
}