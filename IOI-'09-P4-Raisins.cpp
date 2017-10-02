#include <bits/stdc++.h>
using namespace std;

#define MAXN 51

int N,M;
int nums[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];

int solve(int x1, int y1, int x2, int y2){ //top left of rectangle, bottom right of rectangle
  if (x1==x2&&y1==y2){
    return 0;
  }
  else if (dp[x1][y1][x2][y2] != -1){
    return dp[x1][y1][x2][y2];
  }
  else{
    int ans = 999999999;
    int curr = nums[y2][x2]-nums[y1-1][x2]-nums[y2][x1-1]+nums[y1-1][x1-1];
    for (int i=x1;i<x2;i++){
      ans = min(ans,solve(x1,y1,i,y2)+solve(i+1,y1,x2,y2));
    }
    for (int i=y1;i<y2;i++){
      ans = min(ans,solve(x1,y1,x2,i)+solve(x1,i+1,x2,y2));
    }
    //cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << ans+curr << " " << curr << endl;
    return dp[x1][y1][x2][y2] = ans+curr;
  }
}

//prefix[c][d]−prefix[a][d]−prefix[c][b]+prefix[a][b]

int main(){
  scanf("%d %d",&N,&M);
  memset(nums,0,sizeof nums);
  memset(dp,-1,sizeof dp);
  for (int i=1;i<=N;i++){
    for (int j=1;j<=M;j++){
      scanf("%d",&nums[i][j]);
    }
  }
  for (int i=1;i<=N;i++){
    for (int j=1;j<=M;j++){
      nums[i][j] += nums[i-1][j];
    }
  }
  for (int i=1;i<=N;i++){
    for (int j=1;j<=M;j++){
      nums[i][j] += nums[i][j-1];
    }
  }
  printf("%d",solve(1,1,M,N));
}
