
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool see(pair<int, int>& a, pair<int, int>& b, int s) {
    return abs(b.first - a.first) <= s && abs(b.second - a.second) <= s;
}

void init(vector<vector<unsigned char> >& ins, vector<pair<int, int> >& pos, int s) {
    for (int i = 0; i < pos.size(); ++i) {
        for (int j = i+1; j < pos.size(); ++j) {
            if(i == j)
                continue;
            if (see(pos[i], pos[j], s)){
                ins[i][j/8] |= 0x1 << j%8;
                ins[j][i/8] |= 0x1 << i%8;
            }
            else {
                ins[i][j/8] &= ~(0x1 << j%8);
                ins[j][i/8] &= ~(0x1 << i%8);
            }
        }
    }
}

int movep(pair<int, int>& p, int prevrand, int w, int h) {
    int nextrand = (prevrand * 21401 + 25301) % 98765;
    int dir = nextrand % 4;
    if (dir == 0)
        p.first = max(0, p.first - 1);
    else if (dir == 1)
        p.second = min(h - 1, p.second + 1);
    else if (dir == 2)
        p.first = min(w - 1, p.first + 1);
    else
        p.second = max(0, p.second - 1);
    return nextrand;
}

int main() {
    int w, h, n, s, t, r0;
    while (cin >> w) {
        cin >> h >> n >> s >> t >> r0;
        vector<pair<int, int> > pos;
        vector<vector<unsigned char> > ins(n, vector<unsigned char>(n/8+1, 0));
        int x, y;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            pos.push_back(pair<int, int>(x, y));
        }
        init(ins, pos, s);
        for(int i = 0;i<t;i++){
            int incount = 0;
            int outcount = 0;
            for(int j = 0;j<n;j++){
                r0 = movep(pos[j], r0, w, h);
                for(int k = 0;k<n;++k){
                    if(k == j)
                        continue;
                    bool se = see(pos[j], pos[k], s);
                    if(se && ((~ins[j][k/8]) &( 0x1 << k%8))){
                        incount += 2;
                        // ins[j][k] = ins[k][j] = 1;
                        ins[j][k/8] |= 0x1 << k%8;
                        ins[k][j/8] |= 0x1 << j%8;
                    } else if(!se && (ins[j][k/8] &( 0x1 << k%8))){
                        outcount += 2;
                        // ins[j][k] = ins[k][j] = -1;
                        ins[j][k/8] &= ~(0x1 << k%8);
                        ins[k][j/8] &= ~(0x1 << j%8);
                    }
                }
            }
            cout<<incount<<" "<<outcount<<endl;
        }

    }
    return 0;
}