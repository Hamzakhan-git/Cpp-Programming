#include<iostream>
using namespace std;
class Base{
    public:
    void virtual  func(){
        cout<<"Base class function called"<<endl;
    }
};
class Derived : public Base{
    public :
    void func(){
        cout<<"Derived class function called"<<endl;
       }
    
};
int main(){
    Derived Obj2;
    Obj2.func();
    Base* Obj1 = &Obj2;
    Obj1->func();
   
}