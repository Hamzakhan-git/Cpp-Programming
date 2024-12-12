#include<iostream>
#include<stdexcept>
#include<new>
#include<typeinfo>
using namespace std;
class MyException : public exception{
    public:
    const char* what() const noexcept override{
        cout<<"My custom error occured!"<<endl;
    }
};
int fact(int n){
            if(n==0||1){
                return 1;
            }
            return n*fact(n-1);
        }
class Errordemo{
    public:
    
    void divideByZero(int a,int b){
        if(b==0){
            throw runtime_error("Divide by zero error!");
        }
        else{
            cout<<" result:"<< a/b<<endl;
        }
    }
    void outOfBound(){
        int arr[3] = {1,2,3};
        if(true){
            throw out_of_range("Array index out of bound error!");
        }
    }
    void customError(){
        throw MyException();
    }
    void logicalError(){
        
        if(fact(-1)){
            throw logic_error("factorial of negative value can't find");
        }

        
    };
    void badAllocerror(){
        try{
            int* largeArray = new int[100000];
        }
        catch(const bad_alloc&e){
            throw;
        }
    }
    void BadCast(){
        try{
            class Base{virtual void dummy(){}};
            class Derived:public Base{int a;};
            Base* base = new Base;
            Derived* derived = dynamic_cast<Derived*>(base);
            if(derived==nullptr){
                throw bad_cast();
            }
        }
        catch(const bad_cast&e){
            throw;
        }
    }
};
int main(){
    Errordemo demo;
     try{
        demo.divideByZero(10,0);
     }
     catch(const runtime_error&e){
        cout<<"Runtime error occurred: "<<e.what()<<endl;
     }
     try{
        demo.outOfBound();
     }
     catch(const out_of_range&e){
        cout<<"Out of Bound error occurred: "<<e.what()<<endl;
     }
     try{
        demo.customError();
     }
     catch(const MyException&e){
        cout<<"Custom  error occurred: "<<e.what()<<endl;
     }
     try{
        demo.badAllocerror();
     }
     catch(const bad_alloc&e){
        cout<<"Bad Allocation error occurred: "<<e.what()<<endl;
     }
     try{
        demo.BadCast();
     }
     catch(const bad_cast&e){
        cout<<"Bad cast error occurred: "<<e.what()<<endl;
     }
     try{
        demo.logicalError();
     }
     catch(const logic_error&e){
        cout<<"Logic error occurred: "<<e.what()<<endl;
     }
     return 0;
}