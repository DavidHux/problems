#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    int count = 0;
    while(count++ < t){
        int  n, r, c, sr, sc;
        string walks;
        cin >> n>>r>>c>>sr>>sc;
        cin>>walks;
        sr--;
        sc--;
        int ccc = sc, rrr = sr;
        vector<vector<pair<int, int>>> rowVisited(r, vector<pair<int, int>>());
        vector<vector<pair<int, int>>> colVisited(c, vector<pair<int, int>>());

        rowVisited[sr].push_back({sc, sc});
        colVisited[sc].push_back({sr, sr});

        for(int i =0;i<n;++i){
            if(walks[i]=='N'){
                for(int j = 0;j<colVisited[ccc].size();j++){
                    if(colVisited[ccc][j].first<=rrr && colVisited[ccc][j].second>=rrr){
                        colVisited[ccc][j].first -= 1;
                        rrr = colVisited[ccc][j].first;
                        for(int k = j-1;k>=0;k--){
                            if(colVisited[ccc][k].second>= colVisited[ccc][k+1].first){
                                colVisited[ccc][k].second = colVisited[ccc][k+1].second;
                                colVisited[ccc].erase(colVisited[ccc].begin() + k+1);
                                colVisited[ccc][k].first -= 1;
                                rrr = colVisited[ccc][k].first;
                            } else {
                                break;
                            }
                        }
                        if(rowVisited[rrr].size() == 0){
                            rowVisited[rrr].push_back({ccc, ccc});
                        } else {
                            if(rowVisited[rrr].back().second < ccc){
                                rowVisited[rrr].push_back({ccc, ccc});
                            } else {
                                for(int i = 0;i<rowVisited[rrr].size();++i){
                                    if(rowVisited[rrr][i].first > ccc){
                                        rowVisited[rrr].insert(rowVisited[rrr].begin()+i, pair<int, int>(ccc, ccc));
                                        break;
                                    } 
                                }
                            }
                        }
                    }
                }
            } else if(walks[i]=='S'){
                for(int j = 0;j<colVisited[ccc].size();j++){
                    if(colVisited[ccc][j].first<=rrr && colVisited[ccc][j].second>=rrr){
                        colVisited[ccc][j].second++;
                        rrr = colVisited[ccc][j].second;
                        for(int k = j+1;k<colVisited[ccc].size();){
                            if(colVisited[ccc][k].first <= colVisited[ccc][k-1].second){
                                colVisited[ccc][k-1].second = colVisited[ccc][k].second;
                                colVisited[ccc].erase(colVisited[ccc].begin() + k);
                                colVisited[ccc][k-1].second++;
                                rrr = colVisited[ccc][k-1].second;
                            } else {
                                break;
                            }
                        }
                        if(rowVisited[rrr].size() == 0){
                            rowVisited[rrr].push_back({ccc, ccc});
                        } else {
                            if(rowVisited[rrr].back().second < ccc){
                                rowVisited[rrr].push_back({ccc, ccc});
                            } else {
                                for(int i = 0;i<rowVisited[rrr].size();++i){
                                    if(rowVisited[rrr][i].first > ccc){
                                        rowVisited[rrr].insert(rowVisited[rrr].begin()+i, pair<int, int>(ccc, ccc));
                                        break;
                                    } 
                                }
                            }
                        }
                    }
                }
            } else if(walks[i]=='W'){
                for(int j = 0;j<rowVisited[rrr].size();j++){
                    if(rowVisited[rrr][j].first<=ccc && rowVisited[rrr][j].second>=ccc){
                        rowVisited[rrr][j].first -= 1;
                        ccc = rowVisited[rrr][j].first;
                        for(int k = j-1;k>=0;k--){
                            if(rowVisited[rrr][k].second>= rowVisited[rrr][k+1].first){
                                rowVisited[rrr][k].second = rowVisited[rrr][k+1].second;
                                rowVisited[rrr].erase(rowVisited[rrr].begin() + k+1);
                                rowVisited[rrr][k].first -= 1;
                                ccc = rowVisited[rrr][k].first;
                            } else {
                                break;
                            }
                        }
                        if(colVisited[ccc].size() == 0){
                            colVisited[ccc].push_back({rrr, rrr});
                        } else {
                            if(colVisited[ccc].back().second < rrr){
                                colVisited[ccc].push_back({rrr, rrr});
                            } else {
                                for(int i = 0;i<colVisited[ccc].size();++i){
                                    if(colVisited[ccc][i].first > rrr){
                                        colVisited[ccc].insert(colVisited[ccc].begin()+i, pair<int, int>(rrr, rrr));
                                        break;
                                    } 
                                }
                            }
                        }
                    }
                }
            } else if(walks[i]=='E'){
                for(int j = 0;j<rowVisited[rrr].size();j++){
                    if(rowVisited[rrr][j].first<=ccc && rowVisited[rrr][j].second>=ccc){
                        rowVisited[rrr][j].second++;
                        ccc = rowVisited[rrr][j].second;
                        for(int k = j+1;k<rowVisited[rrr].size();){
                            if(rowVisited[rrr][k].first <= rowVisited[rrr][k-1].second){
                                rowVisited[rrr][k-1].second = rowVisited[rrr][k].second;
                                rowVisited[rrr].erase(rowVisited[rrr].begin() + k);
                                rowVisited[rrr][k-1].second++;
                                ccc = rowVisited[rrr][k-1].second;
                            } else {
                                break;
                            }
                        }
                        if(colVisited[ccc].size() == 0){
                            colVisited[ccc].push_back({rrr, rrr});
                        } else {
                            if(colVisited[ccc].back().second < rrr){
                                colVisited[ccc].push_back({rrr, rrr});
                            } else {
                                for(int i = 0;i<colVisited[ccc].size();++i){
                                    if(colVisited[ccc][i].first > rrr){
                                        colVisited[ccc].insert(colVisited[ccc].begin()+i, pair<int, int>(rrr, rrr));
                                        break;
                                    } 
                                }
                            }
                        }
                    }
                }
            }
        }

        cout<<"Case #"<<count<<": "<<rrr+1<<" "<<ccc+1<<endl;
        // printf("%.6f\n", dp[k]); 
    }
}