#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    int count = 0;
    while(count++ < t){
        int  n, k;
        cin >> n>>k;
        vector<int> values(n, 0);
        double sum = 0;
        for(int i =0;i<n;++i){
            cin>>values[i];
            sum += values[i];
        }
        if(k>0)
            sort(values.begin(), values.end(), greater<int>());
        vector<double> dp(k+1, 0);
        dp[0] = sum/n;
        for(int i = 0;i<k;++i){
            double ss = 0;
            for(int j = 0;j<n;++j){
                if(values[j] > dp[i]){
                    ss += values[j];
                } else {
                    ss += dp[i] * (n-j);
                    break;
                }
            }
            dp[i+1] = ss / n;
        }

        cout<<"Case #"<<count<<": ";
        printf("%.6f\n", dp[k]); 
    }
}