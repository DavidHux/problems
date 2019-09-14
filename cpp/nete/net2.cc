#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int n;
    cin>>n;
    int i = 0;
    int a, b;
    set<int> o;
    while(i++<n){
        cin>>a>>b;
        if(a == 1){
            set<int> otmp = o;
            for(auto x:otmp){
                o.insert(x|b);
            }
            o.insert(b);
        }else{
            if(o.find(b) == o.end())
                cout<<"NO"<<endl;
            else
            {
                cout<<"YES"<<endl;
            }
            
        }
    }
    
    return 0;
}