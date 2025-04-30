#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main (void) {
    int N;
    cin >> N;

    vector<string> everyoneKnowsLangs;
    unordered_map<string, int> langs;
    
    string buf;
    int K;

    for (int i = 0; i < N; ++i) {
        cin >> K;
        for (int j = 0; j < K; ++j) {
            cin >> buf;
            langs[buf]++;
        }
    }

    for (auto& lang : langs) {
        if (lang.second == N) {
            everyoneKnowsLangs.push_back(lang.first);
        }
    }

    cout << everyoneKnowsLangs.size() << endl;
    for (auto& lang : everyoneKnowsLangs) {
        cout << lang << endl;
    }
    cout << langs.size() << endl;
    for (auto& lang: langs) {
        cout << lang.first << endl;
    }

    return 0;
}