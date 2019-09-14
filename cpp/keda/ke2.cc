#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> sp(string dli, string to) {
    vector<string> res;
    int p = 0;
    int n = dli.size();
    for (int i = 0; i <= to.size() - n; ++i) {
        if (to.substr(i, n) == dli) {
            res.push_back(to.substr(p, i - p));
            p = i + n;
            i = i + n - 1;
        }
    }
    if (p < to.size())
        res.push_back(to.substr(p));
    return res;
}

int main() {
    string a;
    getline(cin, a);
    auto res = sp(",", a);
    int ret = 0;
    for (auto s : res) {
        // cout << s << endl;
        if (s.size() <= 1)
            continue;
        // int bei = -1, be, endi, end;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] < '0' || s[i] > '9'){
                // cout<<s<<' '<<s[i]<<endl;
                goto l1;
            }
        }
        
        if (s[0] - '0' + s.back() - '0' > 8)
            ret++;
    l1:;
    }
    cout << ret << endl;
    return 0;
}