#include<iostream>
using namespace std;
double Sqroot(double);
int main(){
    double n;
    cout<<"Enter a number:"<<endl;
    cin>>n;
    cout<<"Square root of"<<n<<" is:";
    cout<<Sqroot(n)<<endl;
    return 0;
}
double Sqroot(double n){
    double m=n;
    double a=1;
    while((m-a>=0.01)||(a-m>=0.01)){
        m=(a+m)/2;
        a=n/m;
    }
    return (m+a)/2;

}