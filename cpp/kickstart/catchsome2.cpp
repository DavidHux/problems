#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct cmp{
    bool operator()(const pair<int, int>&a, const pair<int, int>&b){
        return a.first <= b.first;
    }
}

int main(){
    int t;
    cin>>t;
    int count = 0;
    while(count++ < t){
        int  n, k;
        cin >> n>>k;
        vector<pair<int , int>> pos3co(n, {0, 0});
        vector<int> count(n, 0);
        for(int i =0;i<n;++i){
            cin>>pos3co[i].first;
        }
        for(int i =0;i<n;++i){
            cin>>pos3co[i].second;
        }
        sort(pos3co.begin(), pos3co.end(), cmp());
        map<int, vector<int>> mp;
        for(int i = 0;i<pos3co.size();++i){
            auto it = mp.find(pos3co[i].second);
            if(it == mp.end()){
                mp[pos3co[i].second] = vector<int>();
            }
            mp[pos3co[i].second].push_back(pos3co[i].first);
            count[i] = mp[pos3co[i].second].size()-1;
        }
        vector<pair<int, int>> hp;
        // hp.push_back(pos3co)
        int longest = 0;
        map<int, int> compoo;
        for(int i = 0;i<k;i++){
            int curcol = pos3co[i].second
            auto it = compoo.find(curcol);
            if(it == compoo.end()){
                compoo[curcol] = 0;
            }
            compoo[curcol]++;
            longest += pos3co[i].first;
            if(i>0){
                if(pos3co[i-1].second = curcol){
                    longest -= pos3co[i-1].first;
                } else {
                    longest += pos3co[i-1].first;
                    if(compoo[curcol] > 1){
                        longest -= mp[curcol][compoo[curcol]-2]*2;
                    }
                }
            }
        }
        for(auto it = compoo.begin();it!= compoo.end();it++){
            hp.push_back({mp[it->first][it->second-1], it->first});
        }
        make_heap(hp.begin(), hp.end(), cmp());
        int templen = longest;
        templen += 
        for(int i = k;i<n;++i){
            int curcol = pos3co[i].second
            for(int j = compoo[curcol];j<=count[i];++j){
                if(hp.front().second == curcol){
                    pop_heap(hp.begin(), hp.end());
                    hp.erase(hp.end()-1);
                }
                auto x = hp.front();
                templen -= x.first*2;
                templen += mp[x.second][compoo[x.second]-2] * 2;
                compoo[x.second]-=1;
                if(compoo[x.second] > 0){
                    hp.push_back({mp[x.second][compoo[x.second]-1], x.second});
                    push_heap(hp.begin(), hp.end());
                }
            }
        }
        

        cout<<"Case #"<<count<<": ";
        printf("%.6f\n", dp[k]); 
    }
}