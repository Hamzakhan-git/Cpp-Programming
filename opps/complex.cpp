#include<iostream>
using namespace std;
class complex{
int r,i;
public:
void getdata(int x,int y){
    r=x;
    i=y;

}
void display(){
    cout<<"\n"<<r<<"+i"<<i;
}
complex operator+(complex C2){
    complex C3;
    C3.r = r + C2.r;
    C3.i = i + C2.i;
    return C3;

}
};
int main(){
    complex C1,C2,C3;
    C1.getdata(3,6);
    C2.getdata(2,8);
    C1.display();
    C2.display();
    C3 = C1+C2;
    C3.display();
}