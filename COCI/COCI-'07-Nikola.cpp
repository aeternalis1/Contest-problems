#include <bits/stdc++.h>
using namespace std;

long long dp[1001][1001]; //minimum cost to be at block[i] with preceding jump[j]
int arr[1001];

int main(){
  int N;
  queue<pair<int,int>> q; //queue with current block, preceding jump
  pair<int,int> c;
  scanf("%d",&N);
  for (int i=0;i<N;i++){
    scanf("%d",&arr[i]);
  }
  for (int i=0;i<=1000;i++){
    for (int j=0;j<=1000;j++){
      dp[i][j] = 99999999;
    }
  }
  dp[0][0] = 0;
  dp[1][1] = arr[1];
  q.push({1,1});
  while (!q.empty()){
    c = q.front();
    q.pop();
    if (c.first-c.second>=0){ //jump backwards, same distance
      if (dp[c.first-c.second][c.second] > dp[c.first][c.second]+arr[c.first-c.second]){
        dp[c.first-c.second][c.second] = dp[c.first][c.second]+arr[c.first-c.second];
        q.push({c.first-c.second,c.second});
      }
    }
    if (c.first+c.second+1<N){
      if (dp[c.first+c.second+1][c.second+1] > dp[c.first][c.second]+arr[c.first+c.second+1]){
        dp[c.first+c.second+1][c.second+1] = dp[c.first][c.second]+arr[c.first+c.second+1];
        q.push({c.first+c.second+1,c.second+1});
      }
    }
  }
  long long ans = 99999999;
  for (int i=0;i<=N;i++){
    ans = min(ans,dp[N-1][i]);
  }
  printf("%d",ans);
}
