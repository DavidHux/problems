
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int largestRec(vector<int>& lens){
    stack<int> st;
    int m = 0;
    int index;
    lens.push_back(0);
    for(int i=0;i<lens.size();i++){
        while(!st.empty() && lens[st.top()] >= lens[i]){
            index = st.top();
            st.pop();
            m = max(lens[index]*(i - 1 - (st.empty()?-1:st.top())), m);
        }
        st.push(i);
    }
    return m;
}

int main(){
    int t;
    cin>>t;
    int count = 0;
    while(count++ < t){
        int r, c, kma;
        cin >>r>>c>>kma;
        vector<vector<int>> v(r, vector<int>(c, 0));
        for(int i = 0;i<r;++i){
            for(int j = 0;j<c;++j){
                cin>>v[i][j];
            }
        }
        int res = r;
        for(int i = 0;i<c-1;++i){
            vector<int> lens;
            for(int j = 0;j<r;++j){
                int mia = v[j][i], maa = v[j][i];
                for(int k = i+1;k<c;++k){
                    mia = min(v[j][k], mia);
                    maa = max(v[j][k], maa);
                    if((maa - mia) > kma){
                        lens.push_back(k-i);
                        break;
                    }
                }
                if(lens.size() == j){
                    lens.push_back(c-i);
                }
            }
            res = max(res, largestRec(lens));

            l1:;
        }
        

        cout<<"Case #"<<count<<": "<<res<<endl;
    }
}