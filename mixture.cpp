#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll dp[105][105];
ll g(vector<int> &color, int i,int j){
    ll result =0;
    for(int m =i;m<=j;m++){
        result = (result%100 + color[m]%100)%100;
    }
    return result;
}
ll f(vector<int> &color,int i, int j){
    if(i==j) return 0;
    ll result = INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int k=i;k<=j-1;k++){
        result = min(result, f(color,i,k)+f(color,k+1,j)+ g(color,i,k)*g(color,k+1,j));
    }
    return dp[i][j]= result; 
}

 int main(){
    int n;
    while(cin>>n){
        vector<int> color;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            color.push_back(x);
        }
        memset(dp , -1, sizeof dp);
        cout<<f(color,0,color.size()-1)<<endl;
        color.clear();
    }
    return 0;
 }
