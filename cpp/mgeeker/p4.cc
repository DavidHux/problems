
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int x;
    while (cin >> n) {
        // cout<<'n'<<n;
        vector<int> v;
        for(int i = 0;i<n;++i){
            cin>>x;
            v.push_back(x);
            // cout<<x<<' ';
        }
        // cout<<"here"<<endl;
        vector<int> ins(1, 0);
        int temp = 0;
        int mat = INT_MIN;
        for(int i=0;i<n;++i){
            temp += v[i];
            if(temp>mat){
                mat = temp;
                ins.back() = mat;
            }
            if(temp < 0){
                temp = 0;
                mat = 0;
                ins.push_back(0);
            }
        }
        // for(auto aaa : ins)
        //     cout<<aaa<<';';
        // cout<<endl;
        // ins.pop_back();
        int ret = max(0, ins[0]);
        for(int i = 0;i<ins.size()-1;++i){
            for(int j = i+1;j<ins.size();++j){
                if(ins[i]+ins[j] > ret){
                    ret = ins[i]+ins[j];
                }
            }
        }
        cout<<ret<<endl;
    }
    return 0;
}