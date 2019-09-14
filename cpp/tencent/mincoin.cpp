#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int m, n;
    int temp;
    while(cin>>m){
        cin >> n;
        vector<int> v;
        for(int i = 0;i<n;++i){
            cin>>temp;
            v.push_back(temp);
        }
        sort(v.begin(), v.end());

        int su = 0, le = 1;
        int count = 0, index = 0;;
        while(le <= m){
            while(index+1 < v.size() && v[index+1] <= le)
                ++index;
            le += v[index];
            ++count;
        }
        cout<<count<<endl;
    }
}