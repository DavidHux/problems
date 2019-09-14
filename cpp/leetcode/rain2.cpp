#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    struct node{
        node(int a, int b, int h):x(a), y(b), h(h){};
        int x;
        int y;
        int h;
        pair<int, int> operator+(const pair<int, int>& a){
            return {this->x+a.first, this->y+a.second};
        }
    };
    struct cmp{
        bool operator()(const node& a, const node& b){
            return a.h > b.h;
        }
    };
    void print_queue(priority_queue<node, vector<node>, cmp> pq, int c){
        node* v = (node*)&pq.top();
        for(int i = 0;i<c;++i){
            cout<<v[i].x<<' '<<v[i].y<<' '<<v[i].h<<endl;
        }
        cout<<"end\n";
    }
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.size() < 3 || heightMap[0].size() < 3)
            return 0;
        int m = heightMap.size()-1, n = heightMap[0].size();
        int ret = 0;
        vector<vector<bool>> v(m+1, vector<bool>(n, false));
        vector<pair<int, int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        priority_queue<node, vector<node>, cmp> pq;
        int ccc = 0;
        for(int i = 0;i<n;++i){
            pq.push(node(0, i, heightMap[0][i]));
            // print_queue(pq, ++ccc);
            pq.push(node(m, i, heightMap[m][i]));
            // print_queue(pq, ++ccc);
            v[0][i] = true;
            v[m][i] = true;
        }
        for(int i = 1;i<m;++i){
            pq.push(node(i, 0, heightMap[i][0]));
            // print_queue(pq, ++ccc);
            pq.push(node(i, n-1, heightMap[i][n-1]));
            // print_queue(pq, ++ccc);
            v[i][0] = true;
            v[i][n-1] = true;
        }
        
        while(!pq.empty()){
            auto t = pq.top();
            // cout<<"pq.top: "<<t.x<<' '<<t.y<<' '<<t.h<<' '<<pq.size()<<endl;
            pq.pop();
            // cout<<"pq.top: "<<pq.top().x<<' '<<pq.top().y<<' '<<pq.top().h<<' '<<pq.size()<<endl;
            for(auto x:dir){
                auto r = t+x;
                if(r.first>0 && r.first <m&&r.second>0&&r.second<n-1 && !v[r.first][r.second]){
                    v[r.first][r.second] = true;
                    if(heightMap[r.first][r.second] < t.h){
                        ret += t.h-heightMap[r.first][r.second];
                        heightMap[r.first][r.second] = t.h;
                    }
                    // cout<<"r: "<<r.first<<' '<<r.second<<' '<<heightMap[r.first][r.second]<<endl;
                    pq.push({r.first, r.second, heightMap[r.first][r.second]});
                }
            }
        }
        return ret;
    }
};
int main(){
    Solution s;
    vector<vector<int>> a = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    cout<<s.trapRainWater(a)<<endl;;
    return 0;
}