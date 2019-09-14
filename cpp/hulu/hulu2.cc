#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct tree {
    int l, r, mm, a;
};

tree node[4000002];

void build(vector<int>& a, int i, int l, int r) {
    // cout<<i<<' '<<l<<' '<<r<<endl;
    node[i].l = l;
    node[i].r = r;
    if (l == r) {
        node[i].mm = a[l];
        node[i].a = l;
        return;
    }
    int mid = (l + r) / 2;
    build(a, i << 1, l, mid);
    build(a, (i << 1) | 1, mid + 1, r);
    if (node[i << 1].mm > node[(i << 1) | 1].mm) {
        node[i].mm = node[i << 1].mm;
        node[i].a = node[i << 1].a;
    } else {
        node[i].mm = node[(i << 1) | 1].mm;
        node[i].a = node[(i << 1) | 1].a;
    }
    // node[i].mm = max(node[i << 1].mm, node[(i << 1) | 1].mm);
}

vector<int> maa(int i, int l, int r) {
    if (node[i].l == l && node[i].r == r)
        return {node[i].mm, node[i].a};
    int mid = (node[i].l + node[i].r) / 2;
    if (r <= mid)
        return maa(i << 1, l, r);
    else if (l > mid)
        return maa((i << 1) | 1, l, r);
    else {
        auto t1 = maa(i << 1, l, mid);
        auto t2 = maa((i << 1) | 1, mid + 1, r);
        if (t1[0] > t2[0])
            return t1;
        else
            return t2;
    }
    // return max(maa(i << 1, l, mid), maa((i << 1) | 1, mid + 1, r));
}

int suu(int l, int r) {
    // cout<<l<<' '<<r<<endl;
    if (l > r) return 0;
    auto t = maa(1, l, r);
    long long temp = ((long long)t[0] * (t[1] - l + 1)) % 1000000007;
    temp = temp * (r - t[1] + 1) % 1000000007;
    temp += (long long)suu(l, t[1] - 1) + suu(t[1] + 1, r);
    return temp % 1000000007;
}

int suurec(int l1, int r1){
    stack<pair<int, int>> st;
    int l, r;
    int res = 0;
    long long temp;
    st.push({l1, r1});
    while(!st.empty()){
        auto x = st.top();
        st.pop();
        l = x.first, r = x.second;
        if (l > r) continue;
        auto t = maa(1, l, r);
        // cout<<l<<' '<<r<<' '<<t[0]<<' '<<t[1]<<endl;
        temp = ((long long)t[0] * (t[1] - l + 1)) % 1000000007;
        temp = temp * (r - t[1] + 1) % 1000000007;
        res = (res + temp) % 1000000007;
        st.push({t[1] + 1, r});
        st.push({l, t[1] - 1});
    }
    return res;
}
int sumSubarrayMins(vector<int>& A) {
        long long res = 0;
        stack<pair<int, int>> st;
        for(int i = 0;i<A.size();++i){
            while(!st.empty() && st.top().first >= A[i]){
                auto t = st.top();
                st.pop();
                int p = st.empty()? 0: st.top().second+1;
                res = (res + (t.second-p+1)*(i-t.second)*t.first)%1000000007;
            }
            st.push({A[i], i});
        }
        while(!st.empty()){
            auto t = st.top();
            st.pop();
            int i = A.size();
            int p = st.empty()? 0: st.top().second+1;
            res = (res + (t.second-p+1)*(i-t.second)*t.first)%1000000007;
        }
        return res;
    }

int main() {
    int n;
    cout<<123<<endl;
    cin >> n;
    vector<int> aaa(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> aaa[i];
    // cout<<"123"<<endl;
    // build(aaa, 1, 1, n);
    // cout<<"123"<<endl;
    // cout << suurec(1, n) << endl;
    cout<<sumSubarrayMins(aaa)<<endl;
    return 0;
}