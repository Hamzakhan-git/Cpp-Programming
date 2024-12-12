#include<iostream>
using namespace std;
long raiseToPower(int n,int k){
    int result=1;
    for(int i=0;i<k;i++){
        result= result*n;
    }
    return result;
};
int main (){
    int limit;
    cout<<"Enter the limit: ";
    cin>>limit;
    for(int i=0;i<=limit;i++){
        cout<<"Power of 2 is: "<<raiseToPower(2,i);
    }
    return 0;
}
