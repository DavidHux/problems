#include <iostream>
#include <vector>
using namespace std;

vector<int> d;

int main() {
    int n, k;
    cin >> n >> k;
    if (n <= 0) {
        cout << 0 << endl;
        return 0;
    }
    if (n < 2) {
        cout << k << endl;
        return 0;
    }
    d = vector<int>(n, 0);
    d[1] = 2;
    for (int i = 2; i < n; i++) {
        d[i] = d[i - 1] * (i - 1) + d[i - 1] - i + 1;
    }
    int res = k;
    int temp = k;
    for (int i = n - 1; i > 0; --i) {
        temp += d[i];
        res += temp;
    }
    cout << res << endl;
    return 0;
}