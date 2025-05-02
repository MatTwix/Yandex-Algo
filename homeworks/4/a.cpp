#include <iostream>
#include <vector>

using namespace std;

int main (void) {
    vector<int> stack;

    string word;

    while (cin >> word) {
        if (word == "push") {
            int num;
            cin >> num;
            stack.push_back(num);
            cout << "ok" << endl;
        } else if (word == "size") {
            cout << stack.size() << endl;
        } else if (word == "pop") {
            if (!stack.empty()) {
                cout << stack.back() << endl;
                stack.pop_back();
            } else {
                cout << "error" << endl;
            }
        } else if (word == "back") {
            if (!stack.empty()) {
                cout << stack.back() << endl;
            } else {
                cout << "error" << endl;
            }
        } else if (word == "clear") {
            stack.clear();
            cout << "ok" << endl;
        } else if (word == "exit") {
            cout << "bye" << endl;
            break;
        }
    }
}