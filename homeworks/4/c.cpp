#include <iostream>
#include <vector>

using namespace std;

int main (void) {
    vector<int> deque;
    string word;

    while (cin >> word) {
        if (word == "push_back") {
            int num;
            cin >> num;
            deque.push_back(num);
            cout << "ok" << endl;
        } else if (word == "push_front") {
            int num;
            cin >> num;
            deque.insert(deque.begin(), num);
            cout << "ok" << endl;
        } else if (word == "pop_back") {
            if (!deque.empty()) {
                cout << deque.back() << endl;
                deque.pop_back();
            } else {
                cout << "error" << endl;
            }
        } else if (word == "pop_front") {
            if (!deque.empty()) {
                cout << deque.front() << endl;
                deque.erase(deque.begin());
            } else {
                cout << "error" << endl;
            }
        } else if (word == "front") {
            if (!deque.empty()) {
                cout << deque.front() << endl;
            } else {
                cout << "error" << endl;
            }
        } else if (word == "back") {
            if (!deque.empty()) {
                cout << deque.back() << endl;
            } else {
                cout << "error" << endl;
            }
        } else if (word == "size") {
            cout << deque.size() << endl;
        } else if (word == "clear") {
            deque.clear();
            cout << "ok" << endl;
        } else if (word == "exit") {
            cout << "bye" << endl;
            break;
        }
    }
}