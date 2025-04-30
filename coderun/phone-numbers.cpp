#include <iostream>
#include <sstream>

using namespace std;

int main (void) {
    string addedNumber;

    for (int i = 0; i < 4; ++i) {
        string number;
        getline(cin, number);

        while (number.find("+7") != string::npos) {
            number.replace(number.find("+7"), 2, "8");
        }
        while (number.find("-") != string::npos) {
            number.replace(number.find("-"), 1, "");
        }
        while (number.find("(") != string::npos) {
            number.replace(number.find("("), 1, "");
        }
        while (number.find(")") != string::npos) {
            number.replace(number.find(")"), 1, "");
        }

        if (number.length() == 10) {
            number = "8" + number;
        } else if (number.length() == 8) {
            number.erase(0, 1);
            number = "8495" + number;
        } else if (number.length() == 7) {
            number = "8495" + number;
        }

        if (i == 0) {
            addedNumber = number;
        } else if (number == addedNumber) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}