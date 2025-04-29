#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string toBinary(long long num, int length) {
    string binary = "";
    while (num > 0) {
        binary += (num % 2 == 0 ? '0' : '1');
        num /= 2;
    }
    reverse(binary.begin(), binary.end());
    while (binary.size() < length) {
        binary = '0' + binary;
    }
    return binary;
}

long long toDecimal(const string &binary) {
    long long num = 0;
    for (char bit : binary) {
        num = num * 2 + (bit - '0');
    }
    return num;
}

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long maxNum = *max_element(a.begin(), a.end());
    int maxLength = 0;
    while (maxNum > 0) {
        maxNum /= 2;
        ++maxLength;
    }

    vector<string> binaryStrings(n);
    for (int i = 0; i < n; ++i) {
        binaryStrings[i] = toBinary(a[i], maxLength);
    }

    vector<string> resultBinaryStrings = binaryStrings;
    for (int bit = 0; bit < maxLength; ++bit) {
        int countOnes = 0;
        for (int i = 0; i < n; ++i) {
            if (resultBinaryStrings[i][bit] == '1') {
                ++countOnes;
            }
        }
        if (countOnes % 2 != 0) {
            for (int i = 0; i < n; ++i) {
                resultBinaryStrings[i][bit] = (resultBinaryStrings[i][bit] == '1' ? '0' : '1');
            }
        }
    }

    long long xorResult = 0;
    for (const string &binary : resultBinaryStrings) {
        xorResult ^= toDecimal(binary);
    }

    if (xorResult != 0) {
        cout << "impossible" << endl;
    } else {
        for (const string &binary : resultBinaryStrings) {
            cout << toDecimal(binary) << " ";
        }
        cout << endl;
    }

    return 0;
}