#include<iostream>
using namespace std;
class A{
    int a;
    int b;
    public:
    A(int x1, int y1){
        a = x1;
        b = y1;
        cout<<"Constructor A called"<<endl;
        cout<<"Value of a: "<<a<<endl;
        cout<<"Value of b: "<<b<<endl;

    }
};
class B : public A{
    int c;
    int d;
    public:
    B(int x1, int y1 ,int x2, int y2): A( x1, y1){
        c = x2;
        d = y2;
        cout<<"Constructor B called"<<endl;
        cout<<"Value of c: "<<c<<endl;
        cout<<"Value of d: "<<d<<endl;

    }
};
class C : public B{
    int e;
    int f;
    public:
    C(int x1, int y1 ,int x2, int y2, int x3, int y3):B( x1, y1,x2,y2){
        e = x3;
        f = y3;
        cout<<"Constructor C called"<<endl;
        cout<<"Value of e: "<<e<<endl;
        cout<<"Value of f: "<<f<<endl;

    }
};
int main(){
   /*A obj1;
    B obj2;
    C obj3;*/ 
    A obj1(1,2);
    cout<<endl;
    B obj2(3,4,5,6);
    cout<<endl;
    C obj3(7,8,9,10,11,12);
    cout<<endl;
    A obj1c(obj1);
    B obj2c(obj2);
    C obj3c(obj3);


}