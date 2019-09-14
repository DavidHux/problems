#include<iostream>
using namespace std;

class A{
    int a;
    public:
    void f(){
        cout<<234<<endl;
    }
};

int main(){
    A* a = NULL;
    a->f();
    cout<<123<<endl;
    return 0;
}