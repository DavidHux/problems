
#include <iostream>
#include <queue>

using namespace std;

void insert(vector<pair<int, int>>& a, int x, int y){
    if(a.size() == 0){
        a.push_back({x, y});
        return;
    }
    if(a.back().second < x-1){
        a.push_back({x, y});
        return;
    }
    for(int i = 0;i<a.size();i++){
        if(a[i].second < x-1)
            continue;
        if(a[i].first>x){
            a.insert(a.begin()+i, {x, y});
        } else {
            a[i].second = max(y, a[i].second);
        }
        // cout<<"here";
        while(i+1<a.size()){
            if(a[i+1].first <= a[i].second + 1){
                a[i].second = max(a[i+1].second, a[i].second);
                a.erase(a.begin()+i+1);
            } else {
                return;
            }
        }
    } 
}

void remove(vector<pair<int, int>>& a, int x, int y){
    if(a.size() == 0)
        return;
    for(int i = 0;i<a.size();i++){
        if(a[i].second < x)
            continue;
            
        int k = i;
        if(a[i].first < x){
            if(a[i].second >y)
                a.insert(a.begin()+i+1, {y+1, a[i].second});
            a[i].second = x-1;
            k++;
        }
        while(k< a.size() && a[k].second<=y){
            a.erase(a.begin()+k);
        }
        if(k<a.size() && a[k].first <=y)
            a[k].first = y+1;
        return;
    } 
}
int count(vector<vector<pair<int, int>>>& v, int x, int y){
    int count = 0;
    for(int i = 0;i<v.size();++i){
        for(int j = 0;j<v[i].size();++j){
            if(v[i][j].first > y)
                break;
            if((v[i][j].first >=x && v[i][j].first<=y) ||
                (v[i][j].first <=x && v[i][j].second>=x) ){
                    count++;
                    break;
                }
        }
    }
    return count;
}

int main() {
    int n, m, t;
    int x, l, r, v;
    while (cin >> n>>m>>t) {
        vector<vector<pair<int, int>>> vv(t, vector<pair<int, int>>());
        int i = 0;
        while(i++<m){
            cin>>x>>l>>r;
            if(x == 0){
                // cout<<"count"<<x<<' '<<l<<' '<<r<<' '<<endl;
                cout<<count(vv, l, r)<<endl;
            } else if(x == 1){
                // cout<<"add"<<x<<' '<<l<<' '<<r<<' '<<endl;
                cin>>v;
                insert(vv[v-1], l, r);
                // for(auto ff: vv[v-1])
                //     cout<<ff.first <<' '<<ff.second<<"; ";
                // cout<<endl;
            } else {
                // cout<<"delete"<<x<<' '<<l<<' '<<r<<' '<<endl;
                cin>>v;
                remove(vv[v-1], l, r);
                // for(auto ff: vv[v-1])
                //     cout<<ff.first <<' '<<ff.second<<"; ";
                // cout<<endl;
            }
        }
        // printf("%.4f\n", q.top());
    }
    return 0;
}