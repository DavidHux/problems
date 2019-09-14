#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool cmp(string& a, string& b, string& t) {
    return a + b == t || b + a == t;
}

int main() {
    int n;
    cin >> n;
    int i = 0;
    string a, b;
    while (i++ < n) {
        set<string> o;
        cin >> a >> b;
        o.push_back(a);
        while (true) {
            // cout<<a<<endl;
            // if(!a || a.size() == 0)
            //     break;
            int xx = 0;
            for (; xx < a.size(); ++xx) {
                if (a[xx] == '0')
                    break;
            }
            if (xx == a.size())
                break;
            int be = xx;
            string temp = string(a.size() - xx, '1');
            // cout<<"temp "<<temp<<endl;
            while (xx < a.size()) {
                if (a[xx] == '1')
                    temp[xx - be] = '0';
                xx++;
            }
            o.push_back(temp);



            a = temp;
        }
        // cout<<"end"<<endl;
        // for(auto s: o)
        //     cout<<s<<endl;
        int p = 0, q = o.size() - 1;
        bool ff = false;
        while (p <= q) {
            cout<<o[p]<<' '<<o[q]<<endl;
            if (o[p].size() + o[q].size() == b.size()) {
                if (cmp(o[p], o[q], b)) {
                    ff = true;
                    break;
                }
                p++;
                q--;
            } else if (o[p].size() + o[q].size() < b.size()) {
                q--;
            } else {
                p++;
            }
        }
        if (ff)
            cout << "YES" << endl;
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}