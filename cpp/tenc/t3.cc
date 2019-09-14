#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

int main(){
    int n;
    int x0, x1, x2;
    int y0, y1, y2;
    cin>>n;
    int i;
    // cout<<123;
    vector<vector<double>> v(n, vector<double>(3, 0));
    while(i<n){
        cin>>x0>>y0>>x1>>y1>>x2>>y2;

        double a,b,c;
        a = sqrt((double(x0 - x1))* (x0 - x1)+ (y0 - y1)* (y0 - y1));
        b = sqrt((double(x0 - x2))* (x0 - x2)+ (y0 - y2)* (y0 - y2));
        c = sqrt((double(x2 - x1))* (x2 - x1)+ (y2 - y1)* (y2 - y1));
        v[i][0] = a;
        v[i][1] = b;
        v[i][2] = c;
        sort(v[i].begin(), v[i].end()); 

        i++;
    }

    sort(v.begin(), v.end());

    int p = 0;
    int e = n;
    int ret = 0;
    for(int j = 1;j<n;j++){
        if(v[j][0] == v[p][0] &&v[j][1] == v[p][1]&& v[j][2] == v[p][2])
            continue;
        ret += (j-p)*(j-p-1) / 2;
        p = j;
    }

    ret += (e-p)*(e-p-1) / 2;
    cout<<ret<<endl;
    return 0;
}