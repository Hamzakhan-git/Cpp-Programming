#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> p1,pair<int,int> p2){
    double r1 = (p1.first*1.0)/(p1.second*1.0);
    double r2 = (p2.first*1.0)/(p2.second*1.0);
    return r1>r2;
}
double fractional_knapsack(vector<int> &value, vector<int> &weight, int n , int W){
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++){
        arr.push_back({value[i],weight[i]});
    }
    sort(arr.begin(),arr.end(),comp);
    double profit =0;
    for(int i=0;i<n;i++){ 
        if(arr[i].second<=W){
            profit+=arr[i].first;
            W-=arr[i].second;
        }
        else{
        profit+=((arr[i].first*1.0)/(arr[i].second*1.0))*W;
        W=0;
        break;
        }
    }
    return profit;
}
int main(){
    vector<int> value ={60,100,120};
    vector<int> weight ={10,20,30};
    int n =3;
    int W=50;
    cout<<"ans"<<fractional_knapsack(value,weight,n,W)<<endl;
    return 0;

}