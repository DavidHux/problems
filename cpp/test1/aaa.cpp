#include <iostream>

using namespace std;

class Base1 {
   public:
    // int a;
    virtual void f() { cout << "Base1::f" << endl; }
    virtual void f1() { cout << "Base1::f1" << endl; }
    virtual void g(int i = 10) { cout << "Base1::g " <<i<< endl; }

    virtual void h() { cout << "Base1::h" << endl; }
};

class Base2 {
   public:
    virtual void f() { cout << "Base2::f" << endl; }

    virtual void g(int i = 20) { cout << "Base2::g "<< i << endl; }

    virtual void h() { cout << "Base2::h" << endl; }
};

class Base3 {
   public:
    virtual void f() { cout << "Base3::f" << endl; }

    virtual void g(int i = 30) { cout << "Base3::g "<< i << endl; }

    virtual void h() { cout << "Base3::h" << endl; }
};
class Base4:public Base1 {
   public:
    void f2() { cout << "Base4::f1" << endl; }

    // virtual void g() { cout << "Base3::g" << endl; }

    // virtual void h() { cout << "Base3::h" << endl; }
};

class Derive : public Base1, public Base2, public Base3 {
   public:
    virtual void f() { cout << "Derive::f" << endl; }
    void f2() { cout << "Derive::f1" << endl; }
    virtual void g(double i = 10) { cout << "Derive::g "<< endl; }
};

void pp(Base2* b) {
    cout << long(b) << endl;
    b->f();
    
}

typedef void (*Fun)(void);
Derive d;
int main() {

    cout << long(&d) << endl;
    Base2* bb = &d;
    cout << long(bb) << endl;
    // cout<<(long)(bb->g)<<endl;
    bb->g();
    d.g();
//     // pp(bb);
//     return 0;
// }

// int cc() {
    Fun pFun = NULL;
    cout<<sizeof(d)<<endl;;
    // Derive d;
    long long** pVtab = (long long**)&d;
    //Base1's vtable
    cout << (long long)*pVtab << endl;
    cout << (long long)&(pVtab[0]) << endl;
    cout << (long long)&(pVtab[1]) << endl;
    cout << (long long)&pVtab[2] << endl;
    cout << (long long)pVtab[3] << endl;

    //pFun = (Fun)*((int*)*(int*)((int*)&d+0)+0);
    pFun = (Fun)pVtab[0][0];
    pFun();

    pFun = (Fun)pVtab[0][1];
    //pFun = (Fun)*((int*)*(int*)((int*)&d+0)+1);
    pFun();

    //pFun = (Fun)*((int*)*(int*)((int*)&d+0)+2);

    pFun = (Fun)pVtab[0][2];
    pFun();

    //Derive's vtable

    //pFun = (Fun)*((int*)*(int*)((int*)&d+0)+3);
    pFun = (Fun)pVtab[0][3];
    pFun();

    //The tail of the vtable

    pFun = (Fun)pVtab[0][4];
    pFun();
    cout << pFun << endl;

    //Base2's vtable

    //pFun = (Fun)*((int*)*(int*)((int*)&d+1)+0);
    cout<<"here"<<endl;
    pFun = (Fun)pVtab[1][0];
    pFun();
    cout<<"here"<<endl;

    //pFun = (Fun)*((int*)*(int*)((int*)&d+1)+1);

    pFun = (Fun)pVtab[1][1];
    pFun();

    pFun = (Fun)pVtab[1][2];
    pFun();

    //The tail of the vtable

    pFun = (Fun)pVtab[1][3];
    cout << pFun << endl;

    //Base3's vtable

    //pFun = (Fun)*((int*)*(int*)((int*)&d+1)+0);

    pFun = (Fun)pVtab[2][0];
    pFun();

    //pFun = (Fun)*((int*)*(int*)((int*)&d+1)+1);

    pFun = (Fun)pVtab[2][1];
    pFun();

    pFun = (Fun)pVtab[2][2];
    pFun();

    //The tail of the vtable

    pFun = (Fun)pVtab[2][3];
    cout << pFun << endl;

    // pFun = (Fun)pVtab[3][0];
    // cout << pFun << endl;

    return 0;
}
