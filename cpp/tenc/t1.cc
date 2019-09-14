#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int n,m,t;
    cin>>n>>m;
    int i = 0;
    vector<int> v(m+1, 0);
    vector<long long> dp(m+1, 0);
    while(i++<n){
        cin>>t;
        v[t]++;
    }
    dp[1] = v[1] /3;
    dp[2] = dp[1] + v[2]/3;
    int a,b,c;
    int x,y,z;
    int mt;
    for(int j = 3;j<=m;++j){
        a = v[j-2]/3;
        b = v[j-1]/3;
        c = v[j]/3;
        mt = a+b+c;
        x = v[j-2]%3;if(x==0&&a>0){a--;x=3;}
        y = v[j-1]%3;if(y==0&&b>0){b--;y=3;}
        z = v[j]%3;if(z==0&&c>0){c--;z=3;}
        mt = max(mt, a+b+c+min(min(x,y), z));
        dp[j] = max(dp[j-1] + v[j]/3, dp[j-3]+mt);
    }
    cout<<dp[m]<<endl;
    
    return 0;
}