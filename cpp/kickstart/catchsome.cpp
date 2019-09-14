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

        

        cout<<"Case #"<<count<<": ";
        printf("%.6f\n", dp[k]); 
    }
}