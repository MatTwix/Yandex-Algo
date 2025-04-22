#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string str;
    getline(cin, str);

    stack<long long> nums;
    stack<int> signs;

    long long res = 0;
    int sign = 1;
    long long num = 0;

    for (size_t i = 0; i < str.length(); ++i) {
        if (isspace(str[i])) {
            continue;
        }

        if (isdigit(str[i])) {
            num = 0;
            while (i < str.length() && isdigit(str[i])) {
                num = num * 10 + (str[i] - '0');
                ++i;
            }
            --i;
            res += sign * num;
            sign = 1;
        }
        else if (str[i] == '-') {
            sign *= -1;
        }
        else if (str[i] == '(') {
            nums.push(res);
            signs.push(sign);
            res = 0;
            sign = 1;
        }
        else if (str[i] == ')') {
            if (!nums.empty() && !signs.empty()) {
                res = nums.top() + signs.top() * res;
                nums.pop();
                signs.pop();
            }
        }
    }

    cout << res << endl;

    return 0;
}