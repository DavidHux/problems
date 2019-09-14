
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    int x;
    while (cin >> n) {
        priority_queue<double, vector<double>, greater<double>> q;
        // vector<double> a;
        int i = 0;
        while(i++<n){
            cin>>x;
            q.push(x);
        }
        // cout<<q.top()<<endl;
        while(q.size() > 1){
            auto aa = q.top();
            q.pop();
            auto bb = q.top();
            q.pop();
            q.push((aa+bb)/2);
        }
        // cout<<q.top()<<endl;
        printf("%.4f\n", q.top());
    }
    return 0;
}