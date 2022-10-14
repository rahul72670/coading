#include<bits/stdc++.h>
using namespace std;
int dp[10001][10001];
int count_coin_change(vector<int>&v,int n,int s){
     for(int i=0;i<n+1;i++){
         for(int j=0;j<s+1;j++){
             if(j==0)
             dp[i][j]=1;
             if(i==0)
             dp[i][j]=0;
         }
     }
     for(int i=1;i<n+1;i++){
         for(int j=1;j<s+1;j++){
             if(v[i-1]<=j)
             dp[i][j]=dp[i][j-v[i-1]]+dp[i-1][j];
             else
             dp[i][j]=dp[i-1][j];
         }
     }
     return dp[n][s];
}

int main(){
  int n,s;
  cin>>n>>s;
  vector<int>v(n);
  for(int i=0;i<n;i++)
  cin>>v[i];
  cout<<count_coin_change(v,n,s);
    return 0;
}