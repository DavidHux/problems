#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

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

int main() {
    string s;
    string res = "";
    while(1){
        getline(cin, s);
        if(s.size() == 0){
            break;
        }
        auto r = ts(s);
        res += r;
    }
    set<int> err;
    int b = 0, m = 0, q = 0, c = 0;
    for(int i = 0;i<res.size();++i){
        if(res[i] == '['){
            m++;
        } else if(res[i] == ']'){
            m--;
            if(m<0){
                err.insert(1);
            }
        } else if(res[i] == '{'){
            b++;
            if(i>0 && !(res[i-1] == '[' || res[i-1] == ',' || res[i-1] == ':')){
                err.insert(4);
            }
        } else if(res[i] == '}'){
            b--;
            if(b<0){
                err.insert(2);
            }
        } else if(res[i] == '"'){
            q++;
        }
    }
    if(b>0) err.insert(2);
    if(m>0) err.insert(1);
    if(q%2) err.insert(3);
    for(auto x: err)
        cout<<x;

    return 0;
}