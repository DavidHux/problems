#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> sp(string dli, string to){
    vector<string> res;
    int p = 0;
    int n = dli.size();
    for(int i = 0;i<=to.size() - n; ++i){
        if(to.substr(i, n) == dli){
            res.push_back(to.substr(p, i-p));
            p = i+n;
            i = i+n-1;
        }
    }
    if(p<to.size())
        res.push_back(to.substr(p));
    return res;
}

int main() {
    string a;
    getline(cin, a);
    auto strs = sp(" ", a);
    if(strs.size() != 3){
        cout<<0<<endl;
        return 0;
    }
    auto kvs = sp(strs[0], strs[2]);
    vector<string> res;
    // for(auto x: kvs)
    //     cout<<x<<endl;
    for(int i = 0;i<kvs.size();i++){
        if(kvs[i].size() < 1){
            continue;
        }
        auto tt = sp(strs[1], kvs[i]);
        if(tt.size() != 2 || tt[0].size() == 0 || tt[1].size() == 0){
            continue;
        }
        res.push_back(tt[0]+" "+tt[1]);
    }
    cout<<res.size()<<endl;
    for(auto x: res)
        cout<<x<<endl;
    return 0;
}