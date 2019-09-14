#include <iostream>
#include <algorithm>
using namespace std;

long long a2d(int n[]){
    long long ret = 0;
    for(int i = 16;i>=0;--i){
        ret = ret * 10 + n[i];
    }
    return ret;
}
void erasea(int n[]){
    for(int i = 0;i<17;++i){
        n[i] = 0;
    }
}
void print(int a[]){
    for(int i =0;i<17;++i)
        cout<<a[i]<<' ';
    cout<<endl;
}
int main(){
    int nn[17], ln[17], hn[17];
    int t;
    long long n, temp;
    cin>>t;
    int count = 0;
    while(count++ < t){
        erasea(hn);
        erasea(ln);
        erasea(nn);
        cin >> n;
        int bitnum = 0;
        temp = n;
        while(temp>0){
            nn[bitnum] = temp%10;
            temp/=10;
            bitnum++;
        }
        for(int i =bitnum-1;i>=0;i--){
            if(nn[i]%2==0){
                hn[i] = nn[i];
            } else {
                if(nn[i] == 9){
                    while(nn[++i] == 8)
                    ;
                    hn[i] += 2;
                }else {
                    hn[i] = nn[i] +1;
                }
                for(int j = i-1;j>=0;j--){
                    hn[j] = 0;
                }
                break;
            }
        }
        for(int i =bitnum-1;i>=0;i--){
            if(nn[i]%2==0){
                ln[i] = nn[i];
            } else {
                ln[i] = nn[i] -1;
                for(int j = i-1;j>=0;j--){
                    ln[j] = 8;
                }
                break;
            }
        }
        long long hhh = a2d(hn);
        long long lll = a2d(ln);
        long long step = min(hhh-n, n-lll);
        cout<<"Case #"<<count<<": "<<step<<endl;
        // print(nn);
        // print(hn);
        // print(ln); 
    }
}