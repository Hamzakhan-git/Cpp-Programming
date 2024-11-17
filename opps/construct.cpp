#include<iostream>
using namespace std;
class A{
    int a;
    int b;
    public:
    A(){
        a = 1;
        b = 2;
        cout<<"Constructor A called"<<endl;
        cout<<"Value of a: "<<a<<endl;
        cout<<"Value of b: "<<b<<endl;

    }
};
int main(){
    A obj();
}