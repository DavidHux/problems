#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        vector<long long> d(n, 0);
        vector<long long> p(n, 0);
        for(int i = 0;i<n;++i){
            cin>>d[i];
        }
        int moneycount = 0;
        for(int i = 0;i<n;++i){
            cin>>p[i];
            moneycount += p[i];
        }
        vector<vector<long long>> dp(n, vector<long long>(moneycount+1, 0));
        dp[0][p[0]] = d[0];
        int prevm = p[0];
        for(int i = p[0]+1;i<=moneycount;++i){
            dp[0][i] = dp[0][i-1];
        }

        for(int i = 1;i<n;++i){
            int ind1 = moneycount, ind2= 0;
            for(int k = prevm;k<=moneycount;++k){
                if(dp[i-1][k]>= d[i]){
                    ind1 = k;
                    break;
                }
            }
            ind2 = prevm + p[i];
            int iii = min(ind1, ind2);
            // cout<<"iii: " << iii<<' '<<ind1<<' '<<ind2<<endl;

            for(int j = iii;j<= moneycount;++j){
                if(j-p[i] >= prevm){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-p[i]]+d[i]);
                } else{
                    dp[i][j] = dp[i-1][j];
                }
            }
            prevm = iii;
        }
        for(int i = 1;i<=moneycount;++i){
            if(dp[n-1][i] > 0){
                cout<<i<<endl;
                break;
            }
        }
    }
}