#include<iostream>
using namespace std;
class demo{
    private:
    int x;
    public:
    void getdata(){
        cout<<"Enter Number:"<<endl;
        cin>>x;
    }
    void putdata(){
        cout<<"Value of x"<<x<<endl;
    }
    void operator++(int){
        x=x+1;
    }
};
int main(){
    demo aa;
    aa.getdata();
    cout<<"Original:"<<endl;
    aa.putdata();
    aa++;
    cout<<"Valu after increment :";
    aa.putdata();
    return 0;
}