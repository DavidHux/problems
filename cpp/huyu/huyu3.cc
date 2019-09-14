#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool si(string s, long& a, int r) {
    long base = 1;
    long ret = 0;
    int cur;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] >= '0' && s[i] <= '9')
            cur = s[i] - '0';
        else {
            cur = s[i] - 'A' + 10;
        }
        if (cur >= r) return false;
        ret += cur * base;
        base *= r;
    }
    a = ret;
    return true;
}

int main() {
    int n;
    int i = 0;
    string x;
    cin >> n;
    long a, b;
    int m, l;
    while (i++ < n) {
        cin >> m >> l;
        cin >> x;
        a = b = 0;

        long base = 1;
        int cur;
        for (int i = x.size() - 1; i >= 0; i--) {
            if (x[i] >= '0' && x[i] <= '9')
                cur = x[i] - '0';
            else
                cur = x[i] - 'A' + 10;
            if (cur >= l) {
                cout << "error: " << x << ' ' << x.substr(0, i) << endl;
                continue;
            }
            b += cur * base;
            if(si(x.substr(0, i), a, m) && a == b){
                break;
            }
            base *= l;
        }
        cout<<a<<endl;
    }
    return 0;
}