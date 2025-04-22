#include <iostream>
#include <vector>
using namespace std;

struct rectangle {
    int xLd, yLd, xRu, yRu;
};

int main() {
    int W, H, N;
    cin >> W >> H >> N;

    vector<rectangle> photos(N);

    for (int i = 0; i < N; ++i) {
        cin >> photos[i].xLd >> photos[i].yLd >> photos[i].xRu >> photos[i].yRu;
    }

    vector<vector<bool>> correct(W + 1, vector<bool>(H + 1, false));
    for (int x = photos[0].xLd; x <= photos[0].xRu; ++x) {
        for (int y = photos[0].yLd; y <= photos[0].yRu; ++y) {
            correct[x][y] = true;
        }
    }

    for (int k = 1; k < N; ++k) {
        vector<vector<bool>> nextCorrect(W + 1, vector<bool>(H + 1, false));

        for (int x = photos[k].xLd; x <= photos[k].xRu; ++x) {
            for (int y = photos[k].yLd; y <= photos[k].yRu; ++y) {
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        if (abs(dx) + abs(dy) != 1) continue;

                        int nx = x + dx;
                        int ny = y + dy;

                        if (nx >= 1 && nx <= W && ny >= 1 && ny <= H && correct[nx][ny]) {
                            nextCorrect[x][y] = true;
                        }
                    }
                }
            }
        }
        correct = nextCorrect;
    }

    for (int x = 1; x <= W; ++x) {
        for (int y = 1; y <= H; ++y) {
            if (correct[x][y]) {
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";
    return 0;
}