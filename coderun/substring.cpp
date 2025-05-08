#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() 
{
    int N, K;
    cin >> N >> K;

    string str;
    cin >> str;

    vector<int>chars (26, 0);

    int l = 0, mxLen = 0, start;

    for (int r = 0; r < N; ++r) {
        chars[str[r] - 'a']++;

        while (chars[str[r] - 'a'] > K) {
            chars[str[l] - 'a']--;
            l++;
        }

        if (r - l + 1 > mxLen) {
            mxLen = r - l + 1;
            start = l;
        }
    }

    cout << mxLen << " " << start + 1 << endl;

	return 0;
}