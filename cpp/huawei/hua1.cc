#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int k = n / 9;
    int res = -1;
    for (int i = k; i >= 0; --i) {
        if ((n - i * 9) % 4 == 0) {
            res = i + (n - i * 9) / 4;
            break;
        }
    }
    cout << res << endl;
    return 0;
}