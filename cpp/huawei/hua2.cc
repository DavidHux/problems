#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
// #include <bits/c++io.h>

using namespace std;

unordered_map<string, long long> mp;

string ts(string& s) {
    string ret = s;
    for (int i = 0; i < ret.size(); ++i) {
        if (ret[i] == ' ') {
            ret.erase(ret.begin() + i);
            --i;
        }
    }
    return ret;
}
vector<string> splt(string& s) {
    vector<string> ret;
    int prev = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '+') {
            ret.push_back(s.substr(prev, i - prev));
            prev = i + 1;
        }
    }
    ret.push_back(s.substr(prev));
    return ret;
}
bool isi(string& s) {
    return s[0] >= '0' && s[0] <= '9';
    for (auto& x : s) {
        if (!(x >= '0' && x <= '9'))
            return false;
    }
    return true;
}

int main() {
    int n;
    string s;
    cin >> n;
    getline(cin, s);
    int i = 0;

    while (i++ < n) {
        string l, r;
        int ei;
        long long ress = 0;
        bool ok = true;
        getline(cin, s);
        s = ts(s);
        vector<string> x;
        // cout<<"s: "<<s<<endl;
        if (isi(s)) {
            ress = stoll(s);
            goto l1;
        }

        if (s.find('=') == s.size()) {
            if (mp.find(s) != mp.end()) {
                ress = mp[s];
            } else{
                ok = false;
            }
            goto l1;
        }
        ei = s.find('=');
        // cout<<"ei :" <<ei<<endl;
        l = s.substr(0, ei);
        r = s.substr(ei + 1);
        x = splt(r);
        if (isi(l)) {
            ress = stoll(l);
            goto l1;
        }
        // cout<<"l :" <<l<<", r: "<< r<<endl;
        for (auto xx : x) {
            // cout<< xx<<' ';
            if (isi(xx)) {
                auto a = stoll(xx);
                ress += a;
            } else {
                if (mp.find(xx) == mp.end()) {
                    goto l1;
                }
                ress += mp[xx];
            }
        }
        mp[l] = ress;

    l1:;
        if (i == n) {
            if (ok == false || mp.find(l) == mp.end())
                cout << "NA" << endl;
            else
                cout << ress << endl;
        }
    }
    return 0;
}