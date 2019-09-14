
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N = 8;
    vector<int> bottles = {1, 2, 3, 2, 9, 8, 9, 1};
    vector<vector<int>> scores(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        scores[i][i] = 1;
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N - i; j++) {
            int min_score = INT_MAX;
            if (bottles[j] == bottles[j + i]) {
                min_score = i > 1 ? scores[j + 1][j + i - 1] : 1;
            }
            for (int k = 0; k < i; k++) {
                int temp = scores[j][j + k] + scores[j + k + 1][j + i];
                if (temp < min_score) {
                    min_score = temp;
                }
            }
            scores[j][j + i] = min_score;
        }
    }
    cout << scores[0][N - 1];
    return 0;
}