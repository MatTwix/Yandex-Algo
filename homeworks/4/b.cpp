#include <iostream>
#include <vector>

using namespace std;

int main (void) {
    vector<int> queue;
    string word;

    while (cin >> word) {
        if (word == "push") {
            int num;
            cin >> num;
            queue.push_back(num);
            cout << "ok" << endl;
        } else if (word == "size") {
            cout << queue.size() << endl;
        } else if (word == "pop") {
            if (!queue.empty()) {
                cout << queue.front() << endl;
                queue.erase(queue.begin());
            } else {
                cout << "error" << endl;
            }
        } else if (word == "front") {
            if (!queue.empty()) {
                cout << queue.front() << endl;
            } else {
                cout << "error" << endl;
            }
        } else if (word == "clear") {
            queue.clear();
            cout << "ok" << endl;
        } else if (word == "exit") {
            cout << "bye" << endl;
            break;
        }
    }
}