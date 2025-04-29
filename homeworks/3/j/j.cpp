#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdint>

using namespace std;

vector<int> marshal(const string& text) {
    unordered_map<string, int> dict;
    int dictSize = 256; 
    for (int i = 0; i < 256; ++i) {
        dict[string(1, char(i))] = i;
    }

    string current = "";
    vector<int> marshalled;

    for (char c : text) {
        string next = current + c;
        if (dict.find(next) != dict.end()) {
            current = next;
        } else {
            marshalled.push_back(dict[current]);
            dict[next] = dictSize++;
            current = string(1, c);
        }
    }

    if (!current.empty()) {
        marshalled.push_back(dict[current]);
    }

    return marshalled;
}

string unmarshal(const vector<int>& text) {
    unordered_map<int, string> dict;
    int dictSize = 256; 
    for (int i = 0; i < 256; ++i) {
        dict[i] = string(1, char(i));
    }

    string current = "";
    string result;

    for (int code : text) {
        if (dict.find(code) != dict.end()) {
            result += dict[code];
            if (!current.empty()) {
                dict[dictSize++] = current + dict[code][0];
            }
            current = dict[code];
        } else {
            string entry = current + current[0];
            result += entry;
            dict[code] = entry;
            current = entry;
        }
    }

    return result;
}

vector<uint8_t> encodeToBytes(const vector<int>& marshalled) {
    vector<uint8_t> bytes;
    for (int code : marshalled) {
        bytes.push_back((code >> 8) & 0xFF);
        bytes.push_back(code & 0xFF);
    }
    return bytes;
}

vector<int> decodeFromBytes(const vector<uint8_t>& bytes) {
    vector<int> marshalled;
    for (size_t i = 0; i < bytes.size(); i += 2) {
        int code = (bytes[i] << 8) | bytes[i + 1];
        marshalled.push_back(code);
    }
    return marshalled;
}

int main() {
    string type;
    cin >> type;

    if (type == "pack") {
        string text;
        cin >> text;

        vector<int> marshalled = marshal(text);
        vector<uint8_t> bytes = encodeToBytes(marshalled);

        cout << bytes.size() << endl;
        for (size_t i = 0; i < bytes.size(); ++i) {
            if (i > 0) cout << " ";
            cout << int(bytes[i]);
        }
        cout << endl;
    } else if (type == "unpack") {
        int size;
        cin >> size;

        vector<uint8_t> bytes(size);
        for (int i = 0; i < size; ++i) {
            int byte;
            cin >> byte;
            bytes[i] = byte;
        }

        vector<int> marshalled = decodeFromBytes(bytes);
        string unmarshalled = unmarshal(marshalled);

        cout << unmarshalled << endl;
    }

    return 0;
}