#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first)
            return a.second >= b.second;
        return a.first > b.first;
    }
};

int main() {
    priority_queue<pair<int, int> > pq;
    for (int i = 0; i < 10; ++i)
        pq.push(pair<int, int>(rand()%10, rand()%10));
    while (!pq.empty()) {
        cout << pq.top().first << ' ' << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}