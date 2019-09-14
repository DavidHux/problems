
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int m,n;
    int x;
    while (cin >> m>>n) {
        vector<pair<int, pair<int, int>>> v;
        int i = 0;
        for(int i = 0;i<m;++i){
            for(int j = 0;j<n;++j){
                cin>>x;
                v.push_back({x, {i, j}});
            }
        }
        sort(v.begin(), v.end());
        // for(auto x: v){
        //     cout<<x.first<<' '<<x.second.first<<' '<<x.second.second<<endl;
        // }
        long long ma = 0;
        long long temp;
        for(int i = v.size()-1;i>=0;--i){
            for(int j = v.size()-1;j>i;--j){
                if(v[j].second.first != v[i].second.first && v[j].second.second != v[i].second.second){
                    temp = (long long)v[j].first * (long long)v[i].first;
                    if(temp > ma)
                        ma = temp;
                    break;
                }
            }
        }
        cout<<ma<<endl;
    }
    return 0;
}