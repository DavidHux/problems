#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec(100000, 0);
    for (int i = 0; i < 100000 - 2; ++i) vec.pop_back();
    cout << vec.capacity() << endl;
    // vector<int>(vec).swap(vec);
    vector<int>().swap(vec);
    cout << vec.capacity() << endl;
    return 0;
}