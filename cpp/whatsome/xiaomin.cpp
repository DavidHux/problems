#include <iostream>
#include <vector>

using namespace std;

bool checkprev(int id, vector<double>& endt, vector<set<int>>& prev(n, set<int>())){
    for(auto i: prev[id]){
        if(endt[i] == -1)
         return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;++i){
        int n, m, b, e;
        cin >> n >> m >> b >> e;
        vector<double> inp(n, -1);
        vector<double> endt(n, -1);
        vector<int> powp(n 0);
        vector<set<int>> prev(n, set<int>());
        vector<set<int>> next(n, set<int>());
        for(int j = 0;j<n;++j){
            cin >> powp[j];
        }
        for(int j = 0;j<m;++j){
            int x, y;
            cin >> x>>y;
            next[x-1].insert(y-1);
            prev[y-1].insert(x-1);
        }
        prev[b-1].insert(-1);
        while(true){
            int f = false;
            for(int i = 0;i<n;++i){
                if(prev[i].empty()){
                    f = true;
                    for(auto j: next[i]){
                        prev[j].erase(i);
                    }
                }
            }
            if(!f)
                break;
        }
        inp[b-1] = e;
        endt[b-1] = powp[b-1] / inp[b-1];
        set<int> qq;
        for(auto j: next[b-1]){
            qq.insert(j);
        }
        while(!qq.empty()){
           for(auto index: qq){
               if(checkprev(index, endt, prev)){
                   
               }
           }
        }
    }
}