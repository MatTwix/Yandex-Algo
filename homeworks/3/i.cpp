#include <iostream>
#include <vector>

using namespace std;

string marshal (const string& message) {
    int cBits = 0;
    const int len = message.length();

    while ((1 << cBits) < len + cBits + 1) cBits++;

    string res (len + cBits, '0');
    
    int j = 0;
    for (int i = 0; i < len + cBits; ++i) {
        if ((i & (i + 1)) != 0) {
            res[i] = message[j];
            j++;
        }
    }

    int sum;

    for (int i = 0; i < cBits; ++i) {
        sum = 0;
        const int segmLen = 1 << i;

        for (int j = segmLen - 1; j < len + cBits; j += (segmLen << 1)) {
            for (int h = 0; h < segmLen && j + h < len + cBits; ++h) {
                sum += res[j + h] - '0';
            }
        }

        if ((sum & 1) == 0) res[(segmLen - 1)] = '1';
    }

    return res;
}

string unmarshal (const string& message) {
    string buf = message;
    const int len = message.length();

    int sum, n = -1;
    int cBits = 0;

    while ((1 << cBits) <= len) {
        sum = 0;
        const int segmLen = 1 << cBits;

        for (int j = segmLen - 1; j < len; j += (segmLen << 1)) {
            for (int h = 0; h < segmLen && j + h < len; ++h) {
                sum += message[j + h] - '0';
            }
        }

        if((sum & 1) == 0) {
            n += segmLen;
        }
        cBits++;
    }
    
    if (n != -1) buf[n] = (1 - (buf[n] - '0')) + '0';

    int j = 0;
    string res (len - cBits, '0');

    for(int i = 0; i < len; ++i) {
        if ((i & (i + 1)) != 0) {
            res[j] = buf[i];
            j++;
        }
    }

    return res;
}

int main (void) {
    int type;
    cin >> type;

    string message;
    cin >> message;

    if (type == 1) cout << marshal(message) << endl;
    else cout << endl << unmarshal(message) << endl;
}