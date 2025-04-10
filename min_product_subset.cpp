// #include<iostream>
// #include<vector>
// #include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int minProduct(vector<int> &arr){
    int cn=0;
    int cz=0;
    int cp=0;
    int Npdt =1;
    int Ppdt =1;
    int Largest_neg = INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<0){
            cn++;
            Npdt*=arr[i];
            Largest_neg = max(Largest_neg,arr[i]);
        }
        else if(arr[i]==0){
            cz++;

        }
        else{
            cp++;
            Ppdt *=arr[i];
        }
    }
    if(cn==0){
        if(cz>0){
             return 0;
        }
        else{
        auto it = min_element(arr.begin(),arr.end());
        return *it;
        }
    }
    else{
        if(cn%2==0){
            return (Npdt/Largest_neg)*Ppdt;
        }else{
            return Npdt*Ppdt;
        }
    }
}
int main(){
    vector<int> arr {1,-2,-3,6};
    cout<<minProduct(arr)<<endl;
    return 0;
}