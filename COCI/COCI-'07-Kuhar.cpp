#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  int foods[N][6];
  for (int i=0;i<N;i++){
    for (int j=0;j<6;j++){
      scanf("%d",&foods[i][j]);
    }
  }
  int lo = 0;
  int hi = 1000000;
  while (lo < hi){
    int mid = (lo+hi)/2;
    int temp = M;
    for (int i=0;i<N;i++){
      int tar = foods[i][0]*mid-foods[i][1];
      if (tar <= 0) continue;
      int dp[tar+1];
      for (int j=0;j<=tar;j++){
        dp[j] = 99999999;
      }
      dp[0] = 0;
      for (int j=0;j<=tar;j++){
        if (j+foods[i][2] > tar) dp[tar] = min(dp[tar],dp[j]+foods[i][3]);
        else dp[j+foods[i][2]] = min(dp[j+foods[i][2]],dp[j]+foods[i][3]);
        if (j+foods[i][4] > tar) dp[tar] = min(dp[tar],dp[j]+foods[i][5]);
        else dp[j+foods[i][4]] = min(dp[j+foods[i][4]],dp[j]+foods[i][5]);
      }
      temp -= dp[tar];
      if (temp<0) break;
    }
    if (temp<0) hi = mid;
    else lo = mid+1;
  }
  printf("%d",lo-1);
}
