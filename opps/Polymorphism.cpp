#include<iostream>
using namespace std;
class Car{
    string Model_no ;
    string Company;
    int year;
    public: 
    Car(){
       Model_no = "null";
Company = "null";
year = 0000; 
    }
    Car(string a, string b, int c)
{Model_no = a;
Company = b;
year = c;

}
void set(string a, string b, int c){
    Model_no = a;
Company = b;
year = c;

}
void get(){
    cout<<"Model_no: " <<Model_no <<endl;
    cout<<"Company :" <<Company<<endl;
    cout<<"year: " <<year<<endl;
}
};
class Elecar : public Car{
int battery;
public :
Elecar(){
    Car();
}
Elecar(int d):Car(){
battery = d;
}
Elecar(string a, string b, int c, int d):Car( a,b,c){
battery = d;
}
void set(string a, string b, int c){
    Car:: set(a,b,c);
    cout<<"Battery: "<<endl;
    cin>>battery;
}
void set(string a, string b, int c, int d){
    Car :: set(a,b,c);
    battery =d;
}
void get(){
    Car :: get();
    cout<<"Battery: "<<battery<<endl;
}

};
int main(){
    Elecar Obj("WR35T", "Mahindra",2023,98);
    Obj.get();
     
    cout <<endl;
     
    Obj.set("XUIY79","BMW",2024,96);
    Obj.get();
}