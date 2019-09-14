#include <iostream>
#include <string>

using namespace std;

string fto1(string s){
    int num = 0;
    if(s.size() != 5){
        cout<<"error"<<endl;
        return "";
    }
    for(int i = 0;i<5;++i){
        if(s[4-i] == '1'){
            num |= 1 << i;
        }
    }
    char ret;
    if(num <10){
        ret = '0' + num;
    } else {
        ret = 'A'+num -10;
    }
    return string(1, ret);
}

string tto10(string s){
    int num = stoi(s);
    string ret = "0000000000";
    for(int i = 0;i<10;i++){
        if(num & 1){
            ret[9-i] = '1';
        }
        num >>= 1;
    }
    return ret;
}

int main(){
    int t;
    cin>>t;
    string temp;
    for(int t1 = 0;t1 < t;++t1){
        cin >> temp;
        // cout<<temp<<endl;
        int s = temp.size();
        string s10 = "";
        for(int i = 1;i<=s/3;i++){
            string ss = temp.substr(s - i*3, 3);
            s10 = tto10(ss) + s10;
        }
        if(s%3 != 0){
            string ss = temp.substr(0, s%3);
            string s101 = tto10(ss);
            if(s101 != "0000000000"){
                int not0 = 0;
                for(int aa = 0;aa <10;aa++){
                    if(s101[aa] == '1'){
                        not0 = aa;
                        break;
                    }
                }
                s10 = s101.substr(not0) + s10;
            }
        }
        // cout<<s10<<endl;

        int s10s = s10.size();
        string sa = "";
        for(int i = 1;i<=s10s/5;i++){
            string ss = s10.substr(s10s - i*5, 5);
            sa = fto1(ss) + sa;
        }
        if(s10s%5 != 0){
            string ss = s10.substr(0, s10s%5);
            ss = string(5-s10s%5, '0') + ss;
            // cout<<"ss: " << ss<<endl;
            sa = fto1(ss) + sa;
        }
        cout<<sa<<endl;
    }
}