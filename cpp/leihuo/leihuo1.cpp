#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        if(a.first * a.second == b.first * b.second){
            if(min(double(a.first)/a.second, double(a.second)/a.first) == min(double(b.first)/b.second, double(b.second)/b.first))
                return a.first <= b.first;
            return min(double(a.first)/a.second, double(a.second)/a.first) > min(double(b.first)/b.second, double(b.second)/b.first);
        }
        return a.first * a.second <= b.first * b.second;
    }
};

int main(){
    int n;
    while(cin>>n){
        vector<pair<int, int> > v;
        for(int i = 0;i<n;++i){
            int x,y;
            cin>>x>>y;
            v.push_back(pair<int, int>(x, y));
        }
        sort(v.begin(), v.end(), cmp());
        for(auto x:v){
            cout<<x.first<<' '<<x.second<<' ';
        }
        cout<<endl;
    }
    return 0;
}