#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int n;
    cin>>n;
    int i = 0;
    vector<int> a;
    int x;
    while(i++<n){
        cin>>x;
        a.push_back(x);
    }
    for(int z = 0;z<n;++z){
        int mm = 0x7fffffff;
        for(int r = 0;r<n-z;r++){
            mm = min(mm, *max_element(a.begin()+r, a.begin()+r+z+1));
        }
        cout<<mm;
        if(z!=n-1)
            cout<<" ";
        else
        {
            cout<<endl;
        }
    }
    
    return 0;
}