#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
    struct cmp{
        bool operator()(const pair<int ,int> &a, const pair<int, int>&b){
            return a.second>b.second;
        }
    };
    struct cmph{
        bool operator()(const pair<int ,int> &a, const pair<int, int>&b){
            return a.second<b.second;
        }
    };
    void swapa(pair<int, int>&a, pair<int, int>&b){
        swap(a.first, b.first);
        swap(a.second, b.second);
    }
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if(barcodes.size() <= 1)
            return barcodes;
        map<int, int> ccc;
        for(int i = 0;i<barcodes.size();++i){
            if(ccc.find(barcodes[i]) == ccc.end())
                ccc[barcodes[i]]=0;
            ccc[barcodes[i]]++;
        }
        vector<pair<int, int>> v;
        for(auto it = ccc.begin();it!= ccc.end();++it)
            v.push_back({it->first, it->second});
        sort(v.begin(), v.end(), cmp());
        vector<int> ret;
        pair<int, int> a, b;
        a= v.front();
        v.erase(v.begin());
        b = v.front();
        v.erase(v.begin());
        make_heap(v.begin(), v.end(), cmph());
        int totalsize = barcodes.size()-a.second - b.second;
        cmph cmh;
        while(true){
            cout<< a.first<<' '<<a.second<<' '<<b.first<<' '<<b.second<<' '<<v.size()<<endl;
            if(!v.empty() && v.front().second>=totalsize - v.front().second+a.second+b.second){
                pop_heap(v.begin(), v.end(), cmh);
                swap(a, v.back());
                totalsize = totalsize - a.second + v.back().second;
                push_heap(v.begin(), v.end(), cmh);
            }

            ret.push_back(a.first);a.second--;
            ret.push_back(b.first);b.second--;
            if(a.second == 0 && !v.empty()){
                a = v.front();
                pop_heap(v.begin(), v.end(), cmh);
                v.erase(v.end()-1);
                totalsize -= a.second;
            }
            if(b.second == 0 && !v.empty()){
                b = v.front();
                pop_heap(v.begin(), v.end(), cmh);
                v.erase(v.end()-1);
                totalsize -= b.second;
            }
            if(a.second ==0 || b.second == 0)
            break;
        }
            cout<<"weqe "<< a.first<<' '<<a.second<<' '<<b.first<<' '<<b.second<<endl;
        if(b.second >0)
            ret.insert(ret.begin(), b.first);
        if(a.second >0)
            ret.push_back(a.first);
        return ret;
    }
};
int main(){
    vector<int> inn = {1,1,1,1,1,2,2,2,2,3,3,3,4};
    // vector<int> inn = {1,1,1,1,2,2,3,3};
    // vector<int> inn = {7,7,7,8,5,7,5,5,5,8};
    
    Solution s;
    auto ret = s.rearrangeBarcodes(inn);
    for(auto x: ret){
        cout<<x<<' ';
    }
}