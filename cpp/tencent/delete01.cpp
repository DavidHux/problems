#include <iostream>
#include <stack>

using namespace std;

int main(){
    int m;
    char s;
    while(cin>>m){
        stack<char> st;
        for(int i =0;i<m;++i){
            cin>>s;
            if(st.empty()){
                st.push(s);
                continue;
            }
            if(st.top() != s)
                st.pop();
            else
                st.push(s);
        }
        cout<<st.size()<<endl;
    }
}