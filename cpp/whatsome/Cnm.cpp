// 质因数分解 求C(n, m)
/*
质因数分解，C(n,m)=n!/(m!*(n-m)!)，
设n!分解因式后，质因数p的次数为a；对应地m!分解后p的次数为b；(n-m)!分解后p的次数为c；
则C(n,m)分解后，p的次数为a-b-c。计算出所有质因子的次数，它们的积即为答案，
即C(n,m)=p1 a1-b1-c1p2 a2-b2-c2…pk ak-bk-ck。
n!分解后p的次数为：n/p+n/p 2+…+n/p k。
*/
const int MAXN = 1000000;
bool arr[MAXN + 1] = {false};
vector<int> produce_prim_number() {
    vector<int> prim;
    prim.push_back(2);
    int i, j;
    for (i = 3; i * i <= MAXN; i += 2) {
        if (!arr[i]) {
            prim.push_back(i);
            for (j = i * i; j <= MAXN; j += i)
                arr[j] = true;
        }
    }
    while (i <= MAXN) {
        if (!arr[i])
            prim.push_back(i);
        i += 2;
    }
    return prim;
}

//计算n!中素因子p的指数
int Cal(int x, int p) {
    int ans = 0;
    long long rec = p;
    while (x >= rec) {
        ans += x / rec;
        rec *= p;
    }
    return ans;
}

//计算n的k次方对M取模，二分法
int Pow(long long n, int k, int M) {
    long long ans = 1;
    while (k) {
        if (k & 1) {
            ans = (ans * n) % M;
        }
        n = (n * n) % M;
        k >>= 1;
    }
    return ans;
}

//计算C(n,m)
int Combination(int n, int m) {
    const int M = 10007;
    vector<int> prim = produce_prim_number();
    long long ans = 1;
    int num;
    for (int i = 0; i < prim.size() && prim[i] <= n; ++i) {
        num = Cal(n, prim[i]) - Cal(m, prim[i]) - Cal(n - m, prim[i]);
        ans = (ans * Pow(prim[i], num, M)) % M;
    }
    return ans;
}

// 打表
const int M = 10007;
const int MAXN = 1000;
int C[MAXN + 1][MAXN + 1];
void Initial() {
    int i, j;
    for (i = 0; i <= MAXN; ++i) {
        C[0][i] = 0;
        C[i][0] = 1;
    }
    for (i = 1; i <= MAXN; ++i) {
        for (j = 1; j <= MAXN; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
    }
}

int Combination(int n, int m) {
    return C[n][m];
}
