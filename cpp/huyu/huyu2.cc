#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    int i = 0;
    string x;
    cin >> n;
    while (i++ < n) {
        cin >> x;
        string t;
        int prev = 0;
        for (int e = 1; e < x.size(); e++) {
            if (x[e] == x[e - 1] + 1)
                continue;
            if (e >= prev + 4) {
                t += string(1, x[prev]) + '-' + x[e - 1];
            } else {
                t += x.substr(prev, e - prev);
            }
            prev = e;
        }
        if (prev < x.size()) {
            if (x.size() >= prev + 4) {
                t += string(1, x[prev]) + '-' + x[x.size() - 1];
            } else {
                t += x.substr(prev, x.size() - prev);
            }
        }
        cout << t << endl;
    }
    return 0;
}