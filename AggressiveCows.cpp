#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &arr,int n,int m, int maxAllowDis){
    int cows=1,dis=arr[0];
    for(int i=0;i<n;i++){
    if(arr[i]-dis>=maxAllowDis){
   
        cows++;
        dis=arr[i];
    }
    if(cows==m){
        return true;
    }
    }
    return false;
}
int getDistance(vector<int> &arr,int n,int m){
    sort(arr.begin(),arr.end());
    int s=1, e= arr[n-1]-arr[0], ans =-1;
    while(s<= e){
        int mid=s+(e-s)/2;
        if(isPossible(arr,n,m,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;

}


int main(){
    vector<int> arr ={1,2,8,4,9};
    int n=5,m=3;
    cout<<getDistance(arr,n,m)<<endl;



    return 0;
}