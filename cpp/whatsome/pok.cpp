#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

vector<int> stonums(string s, int n){
    string temp;
    vector<int> ret(13, 0);
    for(int i=0;i<n;++i){
        auto it = s.find(' ');
        temp = s.substr(0, it);
        if(it!= s.npos){
            s = s.substr(it+1);
        }
        int nn;
        if(temp == "A"){
            nn = 0;
        } else if(temp == "J"){
            nn = 10;
        } else if(temp == "Q"){
            nn = 11;
        } else if(temp == "K"){
            nn = 12;
        } else if(temp == "10"){
            nn = 9;
        } else{
            nn = stoi(temp) -1;
        }
        ++ret[nn];
    }
    return ret;
}

int main(){
    int m;
    cin>>m;
    for(int m1 = 0;m1<m;++m1){
        int n, index;
        cin >> n;
        string temp;
        getline(cin, temp);
        getline(cin, temp);
        // cout<<"temp:"<<temp<<endl;
        auto p = stonums(temp, n);
        // for(auto i: p)
        //     cout<<i<<" ";
        // cout<<endl;
        int ret = 0;
        for(int i = 0;i<9;++i){
            if(p[i] == 0)
                continue;
            int kk = p[i];
            for(int j = i+1; j<13 && j<i+5;++j){
                if(p[j] == 0){
                    goto l1;
                }
                kk *= p[j];
            }
            ret += kk;
            for(int k = i+5;k<13;++k){
                if(p[k] > 0){
                    kk *= p[k];
                    ret += kk;
                } else {
                    goto l1;
                }
            }

            l1:;
        }
        cout<<ret<<endl;
    }
    return 0;
}