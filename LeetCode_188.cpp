#include<bits/stdc++.h>
using namespace std;
        int dp[1005][105][2];
        int f(vector<int> &arr, int i, int k , bool on){
            if(i==arr.size()) return 0;
            if(dp[i][k][on]!=-1) return dp[i][k][on];
            int ans= INT_MIN;
            ans = f(arr,i+1,k,on);
            if(on){
                ans = max(ans, arr[i] + f(arr,i+1,k-1,false));
            }
            else{
                if(k>0){
                     ans = max(ans, f(arr,i+1,k,true)-arr[i]);
                }
            }
            return dp[i][k][on]= ans;
        } 
        int maxProfit(int k, vector<int>& prices) {
            memset(dp, -1, sizeof dp);
            return f(prices,0,k,false);
        }
    
    int main(){
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> prices(n);
        for(int i=0;i<n;i++){
            cin>>prices[i];
        }
        cout<<maxProfit(k,prices)<<endl;
    }