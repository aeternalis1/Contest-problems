#include <bits/stdc++.h>
using namespace std;

//Method: https://dmoj.ca/problem/ccc15s5/editorial

int N,M;
vector<int>pies;
vector<int>pies2;
int dp[3002][2][102][102];

int solve(int pos, int taken, int l, int r){
  if (dp[pos][taken][l][r] != -1){
    return dp[pos][taken][l][r];
  }
  if (pos == N){
    if (l<=r){
      if (taken){
        dp[pos][taken][l][r] = solve(pos,false,l+1,r);
        return dp[pos][taken][l][r];
      }
      else{
        dp[pos][taken][l][r] = solve(pos,true,l,r-1)+pies2[r];
        return dp[pos][taken][l][r];
      }
    }
    else{
      dp[pos][taken][l][r] = 0;
      return 0;
    }
  }
  if (taken){
    dp[pos][taken][l][r] = solve(pos+1,false,l,r);
    if (l <= r){
      dp[pos][taken][l][r] = max(dp[pos][taken][l][r],solve(pos,false,l+1,r));
    }
  }
  else{
    dp[pos][taken][l][r] = max(solve(pos,true,l,r),solve(pos+1,true,l,r)+pies[pos]);
    if (l <= r){
      dp[pos][taken][l][r] = max(solve(pos,true,l,r-1)+pies2[r],dp[pos][taken][l][r]);
    }
  }
  return dp[pos][taken][l][r];
}

int main(){
  scanf("%d",&N);
  int a;
  for (int i=0;i<N;i++){
    scanf("%d",&a);
    pies.push_back(a);
  }
  scanf("%d",&M);
  for (int i=0;i<M;i++){
    scanf("%d",&a);
    pies2.push_back(a);
  }
  memset(dp,-1,sizeof dp);
  sort(pies2.begin(),pies2.end());
  if (M>0){
    printf("%d",solve(0,0,0,M-1));
  }
  else{
    printf("%d",solve(0,0,1,0));
  }
  return 0;
}
