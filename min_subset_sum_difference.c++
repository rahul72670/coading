#include<bits/stdc++.h>
using namespace std;
bool dp[10001][10001];
int subSumDiff(vector<int>v,int n,int r){
      for(int i=0;i<n+1;i++){
          for(int j=0;j<r+1;j++){
              if(j==0)
              dp[i][j]=1;
              else if(i==0)
              dp[i][j]=0;
          }
      }
      for(int i=1;i<n+1;i++){
          for(int j=0;j<r+1;j++){
              if(v[i-1]<=j)
              dp[i][j]=dp[i-1][j-v[i-1]]||dp[i-1][j];
              else
              dp[i][j]=dp[i-1][j];
          }
      }
      int mn=INT_MAX;
      for(int j=0;j<=r/2;j++)
        if(dp[n][j])
        mn=min(mn,r-2*j);

        return mn;
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    int s=0;
    for(int i=0;i<n;i++){
    cin>>v[i];
    s+=v[i];
    }
    cout<<subSumDiff(v,n,s);
    return 0;
}