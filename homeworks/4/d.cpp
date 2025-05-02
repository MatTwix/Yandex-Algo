#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main (void) {
    int N;
    cin >> N;
    cin.ignore();

    vector<string> stack;

    string line;

    for (int i = 0; i < N; ++i) {
        getline(cin, line);
        stringstream ss(line);

        string word;
        ss >> word;

        if (word == "Run") {
            string program, buf;

            while (ss >> buf) program += " " + buf;
            program.erase(0, 1);

            stack.insert(stack.begin(), program);
            cout << stack[0] << endl;
        } else {
            int k = 0;
            size_t pos = 0;
            while ((pos = line.find("+Tab", pos)) != string::npos) {
                ++k;
                pos += 4;
            }
            int idx = k % stack.size();
            string buf = stack[idx];
            stack.erase(stack.begin() + idx);
            stack.insert(stack.begin(), buf);
            cout << stack[0] << endl;
        }
    }
}