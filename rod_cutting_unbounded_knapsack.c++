#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int rod_cut(vector<int>&l,vector<int>&p,int n,int N){
     for(int i=0;i<n+1;i++){
        for(int j=0;j<N+1;j++){
            if(j==0||i==0)
            dp[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<N+1;j++){
            if(l[i-1]<=j){
                dp[i][j]=max((p[i-1]+dp[i][j-l[i-1]]),dp[i-1][j]);
            }
            else 
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][N];
}

int main(){
  int n,N;
  cin>>n>>N;
  vector<int>l(n),p(n);
  for(int i=0;i<n;i++)
  cin>>l[i];
  for(int i=0;i<n;i++)
  cin>>p[i];
    cout<<rod_cut(l,p,n,N);
    return 0;
}